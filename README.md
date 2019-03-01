# Generate-Image-with-Chinese-Characters-inside
python, Opencv, freetype
Enclosed please see python sample code to draw text into jpg file.
Please write a C or C++ code to implement the same functionality for arbitrary text input.

First, you may need to download simhei.ttf file and put it under the same directory of your python code.
Please keep the sample code confidential.

###########################################
from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw 

img = Image.new("RGB", (224, 224), (0,0,0))
draw = ImageDraw.Draw(img)
font = ImageFonttruetype("simhei.ttf", 16)
draw.text((0, 0),"Sample Text",(255,255,255),font=font)
img.save("Sample", "JPEG")
############################################

Please test your code in Linux, and send your source code with executables with a detailed instructions on how to make and run your code, and how to install dependencies if necessary.

In addition, please extend your c++ implementations to be more generalized, 
including: 
a. Not only support simhei.ttf, can support arbitrary font file within the same directory.
b. How to support other languages, such as Chinese, Japanese, Korean and etc.
c. How to Change your Fontsize, (currently it is fixed size of 16)?
d. How to fit in long text input that needs more than one line and needs to change into another line within the image?
e. How to change the position in the image for the first word of the text?
 f. How to optimize your code and make it faster?
 g. How to reduce memory footprint as much as possible?
