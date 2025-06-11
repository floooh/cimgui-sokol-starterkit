# NOTE: run with `source install_emsdk.sh`

# LAST GOOD VERSION:
# HASH=848e67bef087f70999f57976248ec4358d459bbd
# FIRST BAD VERSION:
HASH=2f2fc539017bc8e062699b5f05043a0dc2381ea4

git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install $HASH
./emsdk activate $HASH
source ./emsdk_env.sh
cd ..