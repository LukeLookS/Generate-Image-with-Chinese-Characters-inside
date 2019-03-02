# Generate-Image-with-inside-Chinese-Characters
python, Opencv, freetype
## Used C/C++ code to implement the same functionality for arbitrary text input.

```
from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw 


img = Image.new("RGB", (224, 224), (0,0,0))
draw = ImageDraw.Draw(img)
font = ImageFonttruetype("simhei.ttf", 16)
draw.text((0, 0),"Sample Text",(255,255,255),font=font)
img.save("Sample", "JPEG")
```

### basic functions
1. support simhei.ttf, can support arbitrary font file within the same directory
2. support other languages, such as Chinese, Japanese, Korean and etc
3. Change your Fontsize, (currently it is fixed size of 16)
4. fit in long text input that needs more than one line and needs to change into another line within the image
5. change the position in the image for the first word of the text
6. optimize your code and make it faster
7. reduce memory footprint as much as possible

### how to build and run my code

安装opencv

详情请参考http://www.codebind.com/cpp-tutorial/install-opencv-ubuntu-cpp/

$ sudo apt-get update 

$ sudo apt-get upgrade

Install Dependencies

$ sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev 

$ sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev

$ sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev

Get Opencv

$ sudo -s

$ cd /opt

/opt$ git clone https://github.com/Itseez/opencv.git

/opt$ git clone https://github.com/Itseez/opencv_contrib.git

Build and install opencv

/opt$ cd opencv

/opt/opencv$ mkdir release

/opt/opencv$ cd release

/opt/opencv/release$ cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/

/opt/opencv/release$ make -j4

/opt/opencv/release$ make install

/opt/opencv/release$ ldconfig

/opt/opencv/release$ exit

/opt/opencv/release$ cd ~

$ sudo apt-get install libopencv-dev

Check if opencv is installed

pkg-config --modversion opencv

Install freetype-2.4.0

https://drive.google.com/file/d/1FiDv-TepEJCSDe_J7KzQa0PQG5GUiPQG/view?usp=sharing

I have already written sh command for freetype installation 

 

If you cannot download through the link, you can download the freetype2.4.0 through website https://sourceforge.net/projects/freetype/files/freetype2/2.4.10/

 

And install it through root privilege and use command below

tar xjf freetype-2.4.10.tar.bz2

cd freetype-2.4.10

./configure

make

make install

Usage of my code

配置好环境后，直接进入文件里面

Sh run.sh

成功后会保存sample.jpg 作为output在当前文件夹下

如果想要更改input text的内容，可以在main.cpp里面更改sample text的输入内容

Run.sh里面可以更改输入文字的location, font_type, font_size, 以及选择输入内容是否为英文，具体如下

命令行参数

# paraser      (x,y) fronsize font_trype(0~4) string(0 or 1 ) string_type(0 or 1)

./build/chinese 50 50   32          2            0          0

参数解析

坐标位置(50,50),   取值为（0-224）因为设定的image的大小为224x224

字体大小为32，

字体类型为2，取值为（0 1 2 3 4）包括{"calibri","msyh","simhei","times","timesi"};  

其中msyh,simhei 属于中文字体，其他属于英文字体

字符串标号为1，取值为（0 1）（选择0为英文，1为中文）英文的内部已有换行机制。

字符串类型为1. 取值为（0 1）（对应的0为英文，1为中文）

 
