make cleanall
clear
export LD_LIBRARY_PATH="./libs"
make
# clear
./interp "$@"

