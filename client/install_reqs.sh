git clone https://github.com/fpagliughi/sockpp.git
cd sockpp
git checkout e6c4688
cmake -Bbuild .
cmake --build build/
sudo cmake --build build/ --target install
cd ..
rm -rf sockpp