#include "ProgramInterpreter.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using namespace xercesc;

void ProgramInterpreter::loadLibraries()
{
    _LibSet.addLibInterface("libInterp4Move.so");
    _LibSet.addLibInterface("libInterp4Set.so");
    _LibSet.addLibInterface("libInterp4Rotate.so");
    _LibSet.addLibInterface("libInterp4Pause.so");
}

void ProgramInterpreter::printLoadedLibs()
{
    cout << "Wczytane wtyczki:" << endl;
    for(auto &lib : _LibSet.LibsCollection)
        cout << lib.first << endl;

}

bool ProgramInterpreter::read_xml_file(string xmlfile)
{
    try
    {
        XMLPlatformUtils::Initialize();
    }
    catch(const XMLException &to_catch)
    {
        char *msg = XMLString::transcode(to_catch.getMessage());
        cerr << "Error during initialization: " << endl;
        cerr << msg << endl;
        XMLString::release(&msg);
        return 1;
    }

    SAX2XMLReader *parser = XMLReaderFactory::createXMLReader();

    parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
    parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    parser->setFeature(XMLUni::fgXercesDynamic, false);
    parser->setFeature(XMLUni::fgXercesSchema, true);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
    parser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

    DefaultHandler *handler = new XMLInterp4Config(_Config);
    parser->setContentHandler(handler);
    parser->setErrorHandler(handler);

    try
    {
        if(!parser->loadGrammar(xsdfile.c_str(), xercesc::Grammar::SchemaGrammarType, true))
            exit_app_with_msg("Cannot load grammar file!");
        
        parser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, true);
        parser->parse(xmlfile.c_str());
    }
    catch (const SAXParseException &Exception)
    {
        char *msg = XMLString::transcode(Exception.getMessage());
        cerr << msg << endl;
        XMLString::release(&msg);
        return false;
    }
    catch (const SAXParseException &Exception)
    {
        char *msg = XMLString::transcode(Exception.getMessage());
        char *file_id = xercesc::XMLString::transcode(Exception.getMessage());

        cerr << "Error:" << endl;
        cerr << "\t File: " << file_id << endl;
        cerr << "\t Line: " << Exception.getLineNumber() << endl;
        cerr << "\t Message: " << msg << endl;

        XMLString::release(&msg);
        XMLString::release(&file_id);
        return false;
    }
    catch (...)
    {
        cerr << "Undefined error occurred!" << endl;
        return false;
    }

    delete parser;
    delete handler;
    return true;
}