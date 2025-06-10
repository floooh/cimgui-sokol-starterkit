# NOTE: run with `source install_emsdk.sh`

# LAST GOOD VERSION:
# HASH=8103ffedfb0c42d231c6af6859a5a1a832260b43
# FIRST BAD VERSION:
HASH=65c4e7ad07766fdc9dc514159bd5ac4449393e17

git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install $HASH
./emsdk activate $HASH
source ./emsdk_env.sh
cd ..