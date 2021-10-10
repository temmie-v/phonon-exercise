import pandas as pd
from PIL import Image, ImageDraw, ImageFilter

data = pd.read_csv("./ex2anime.dat", header=None)
images = []

for t in range(350):
    im = Image.new('RGB', (800, 500), (0, 0, 0))
    draw = ImageDraw.Draw(im)
    for i in range(2):
        for j in range(5):
            draw.line((25 + 400 * i, 100 * (0.5 + j),
                      375 + 400 * i, 100 * (0.5 + j)), fill=(128, 128, 128), width=1)
            for k in range(15):
                x = (400 * i + 25 * (k + 1))
                y = 100 * (0.5 + j) + 20 * data[k + i * 15 + j * 30][t]
                if k % 2 == 1:
                    col = 7
                else:
                    col = 4
                draw.ellipse((x - col, y - col, x + col, y + col), fill=(255,
                         255, 85 * (col - 4)), outline=(255, 255, 85 * (col - 4)))
    images.append(im)

images[0].save('movie.gif', save_all=True, append_images=images[1:], optimize=False, duration=20, loop=0)