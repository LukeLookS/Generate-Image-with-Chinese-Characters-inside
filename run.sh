# run.sh file
# author: Mengjie Shi
rm -rf build
rm SAMPLE.JPG

mkdir build
cd build

cmake ..
make

cd ..
# font_type include fronttype[5] = {"calibri","msyh","simhei","times","timesi"};  
# 0,3,4 for English  1,2 for chinese
# string is same with string type
# 0 for English 1 for Chinese
# x, y is location, fontsize is fontsize
# you can change the input text in main.cpp
# parser 		(x,y) fontsize font_type(0~4) string(0 or 1 ) string_type(0 or 1)
./build/chinese 50 50 	32 			2 			 1		1	

echo "success"
