CC=~/llvm-workspace/clang+llvm-3.7.0-x86_64-apple-darwin/bin/clang
CXX=~/llvm-workspace/clang+llvm-3.7.0-x86_64-apple-darwin/bin/clang++

main: main.cpp
	$(CXX) -g main.cpp -o main -std=c++11

clean:
	rm main

