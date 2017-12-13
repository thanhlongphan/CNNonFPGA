import os
import numpy as np
import cv2
import types

np.set_printoptions(threshold=np.nan)

labels = []
images = []

print("Bilder werden resized...")
for i, filename in enumerate(os.listdir("C:\\Users\\Kevin\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\data\\train")):
    #print(filename)
    # if 'cat' in filename:
    #     labels.append(0)
    # if 'dog' in filename:
    #     labels.append(1)
    im = cv2.imread(filename)

    resized_image = cv2.resize(im, (64, 64))
    #print(resized_image, filename)
    images.append(resized_image)

    #if i == 50:      
    #    break


    # Speichern als eine .txt für jedes Bild <-----------
    f = open("C:\\Users\\Kevin\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\data\\trainpre\\"+filename+".txt", 'w', encoding='utf-8', errors='ignore')
    f.write(str(resized_image))

resized_images = np.array(images)
#print(len(resized_images))


# Speichern als eine große .txt <-----------------
print("Datei wird erstellt..")
f1 = open("resized_images.txt", 'w', encoding='utf-8', errors='ignore')
for i, im in enumerate(resized_images):
    #if i == 50:
    #    break
    f1.write(str(im))
f1.close()

# Speichern als .bin <-----------
f2 = open("resized_images.bin", 'wb')
resized_images.tofile(f2)
f2.close()



#print(str(test))
