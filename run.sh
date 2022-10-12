make
export LD_LIBRARY_PATH="./libs"; ./interp
clear
./interp "$@"
echo
echo
make clean
