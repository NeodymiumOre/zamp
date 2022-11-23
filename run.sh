# make cleanall
# clear
export LD_LIBRARY_PATH="./libs"
make
# clear
# ./interp "$@"
./xmlinterp4config config/config.cmd config/config.xml

