//Menu created by Mohamed Ahmed Hamed
//Authors : Mohamed Ahmed Hamed 20231131 ,Islam Ahmed Salah Dawood 20230056 ,Zeyad Ali Elazzap Mohamed 20230157
//Purpose : menu of 15 filters.
//version : 3.0
//Date of last change : 13/04/2024
//Section : S15 , S16

//Note that I did the bouns part with myself only so please give the grade for me only ,
// Mohamed and Zyad are not responsible for any problem of Islam's filters (4,10) because he is not making any effort
// for fixing them, he told as to let them as it is.

//20231131 did the 3 (Invert) , 6 (Rotate) , 9 (Adding a Frame) , 12 (Blur); Bouns (Individually) : 13 ( Sunlight ) , 16 (Purple the image) , 17 (infra-red ) filters.
//20230056 did the 1 ( Grayscale ) , 4 ( Merge images  ) , 7 ( Darken and Lighten ) , 10 ( DetectImageEdges  ) filters.
//20230157 did the 2 (Black and white filter) , 5 (Flip filter) , 8 ( Crop Images) , 11 ( Resizing Images ) filters.



#include <string>
#include <iostream>
using namespace std;
#include "Image_Class.h"
#include <cmath>

void Black_and_White() {
    string filename;
    cout << "Please enter colored image name to turn to Black and White: ";
    cin >> filename;

    Image Colored_image(filename);

    for (int i = 0; i < Colored_image.width; ++i) {
        for (int j = 0; j < Colored_image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += Colored_image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average
            //if the average less than or equal to 127 make this pixel black
            if (avg<=127)
            {
                Colored_image(i, j, 0) = 0;
                Colored_image(i, j, 1) = 0;
                Colored_image(i, j, 2) = 0;
            }
                //otherwise make it white
            else
            {
                Colored_image(i, j, 0) = 255;
                Colored_image(i, j, 1) = 255;
                Colored_image(i, j, 2) = 255;
            }
        }
    }

    cout << "Image processed successfully." << endl;
    string choice;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        string filenamee;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filenamee;
        Colored_image.saveImage(filenamee);
        // Code to save the image with the given filename
        cout << "Image saved as " << filenamee << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }
}

void ConvertToGrayScale() {
    string filename;
    cout << "Please enter colored image name to grayscale: ";
    cin >> filename;

    Image Colored_Name(filename);
    cout << "Loaded Successfully"<< endl;
    // Convert to grayscale
    for(int i = 0; i < Colored_Name.height; i++) {
        for(int j = 0; j < Colored_Name.width; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; k++)
                avg += Colored_Name(j, i, k);
            avg /= 3; // Calculate average
            for (int k = 0; k < 3; k++)
                Colored_Name(j, i, k) = avg;
        }
    }

    // store the grayscale image
    string  choice , outputImageName;
    cout << "Image processed successfully." << endl;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;
    if (choice == "yes") {
        string outputImageName;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> outputImageName;
        Colored_Name.saveImage(outputImageName);
        cout << "Saved Successfully." << endl ;
        // Code to save the image with the given filename
        cout << "Image saved as " << outputImageName << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }


}
void Invert() {
    string name;
    cout << "Please enter colored image name to invert it: ";
    cin >> name ;
    Image my_image(name);
    for (int i = 0; i < my_image.width; ++i) {
        for (int j = 0; j < my_image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                my_image(i, j, k) = 255 - my_image(i, j, k);
            }
        }
    }
    string  choice , outputImageName;
    cout << "Image processed successfully." << endl;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;
    if (choice == "yes") {
        string outputImageName;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> outputImageName;
        my_image.saveImage(outputImageName);
        // Code to save the image with the given filename
        cout << "Image saved as " << outputImageName << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }

}

void FlipImage() {
    string name;
    cout << "Please enter image name to flip: ";
    cin >> name;
    Image image(name);
    char direction;
    cout << "Please choose how you want to flip the image \n";
    cout << "Enter [h] to flip horizontally: \n";
    cout << "Enter [v] to flip vertically: \n";
    cout << "Enter here: ";
    cin >> direction;

    switch (direction) {
        case 'h':
            for(int i = 0; i < image.width /2; i++) {
                for(int j = 0; j < image.height; j++) {
                    for(int k = 0; k < 3; k++) {
                        unsigned int avg = image(i, j, k);
                        image(i, j, k) = image(image.width - 1 - i, j, k);
                        image(image.width - 1 - i, j, k) = avg;

                    }
                }
            }
            cout << "Image has been flipped horizontally successfully. " << endl;
            break;

        case 'v':
            for(int i = 0; i < image.width; i++) {
                for(int j = 0; j < image.height / 2; j++) {
                    for(int k = 0; k < 3; k++) {
                        unsigned int temp = image(i, j, k);
                        image(i, j, k) = image(i, image.height - 1 - j, k);
                        image(i, image.height - 1 - j, k) = temp;
                    }
                }
            }
            cout << "Image has been flipped vertically successfully. " << endl;
            break;

        default:
            cout << "Invalid direction. No flip performed." << endl;
            return;
    }

    string  choice , outputImageName;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;
    if (choice == "yes") {
        string outputImageName;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> outputImageName;
        image.saveImage(outputImageName);
        // Code to save the image with the given filename
        cout << "Image saved as " << outputImageName << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }
}

void AdjustImageBrightness() {
    string choice;
    cout << "Please enter your choice: \n 1) Dark image \n 2) Light image \nEnter here: ";
    cin >> choice;

    if (choice == "1") {
        string filename;
        cout << "Please enter the name of the image you want to make it more DARK: ";
        cin >> filename;
        Image my_image (filename);

        for (int i = 0; i < my_image.width; i++) {
            for (int j = 0; j < my_image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    int value = my_image(i, j, k);
                    my_image(i, j, k) = max(0, value - value / 2);
                }
            }
        }
        string  choice , outputImageName;
        cout << "Image processed successfully." << endl;
        cout << "Do you want to store the image? (yes/no): ";
        cin >> choice;
        if (choice == "yes") {
            string outputImageName;
            cout << "Please enter name to your new image to store\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
            cin >> outputImageName;
            my_image.saveImage(outputImageName);
            // Code to save the image with the given filename
            cout << "Image saved as " << outputImageName << endl;
        } else if (choice == "no") {
            cout << "Image not saved." << endl;
        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }
    } else if (choice == "2") {
        string filename;
        cout << "Please enter the name of the image you want to make it more LIGHT: ";
        cin >> filename;

        Image my_image(filename);
        for (int i = 0; i < my_image.width; i++) {
            for (int j = 0; j < my_image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    int value1 = my_image(i, j, k);
                    my_image(i, j, k) = min(255, value1 + (255 - value1) / 2);
                }
            }
        }
        string  choice , outputImageName;
        cout << "Image processed successfully." << endl;
        cout << "Do you want to store the image? (yes/no): ";
        cin >> choice;
        if (choice == "yes") {
            string outputImageName;
            cout << "Please enter name to your new image to store\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
            cin >> outputImageName;
            my_image.saveImage(outputImageName);
            // Code to save the image with the given filename
            cout << "Image saved as " << outputImageName << endl;
        } else if (choice == "no") {
            cout << "Image not saved." << endl;
        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
}


void MergeImages()
{
    while (true)
    {
        try
        {
            string img1,img2;
            cout << "Enter the image1 Name: ";
            cin >> img1;
            cout << "Enter the Image2 Name: ";
            cin >> img2;
            Image image1(img1),image2(img2);
            if (image1.width < image2.width && image1.height < image2.height)
            {

                Image imageEdit(image1.width,image1.height);
                for (int i = 0; i < imageEdit.width; ++i)
                {
                    for (int j = 0; j < imageEdit.height; ++j)
                    {
                        for (int k = 0; k < 3; ++k)
                        {
                            imageEdit(i,j,k) = (image1(i,j,k) + image2(i,j,k)) / 2;
                        }
                    }
                }
                if (imageEdit.saveImage(img1))
                {
                    imageEdit.saveImage(img1);
                    string  choice , outputImageName;
                    cout << "Image processed successfully." << endl;
                    cout << "Do you want to store the image? (yes/no): ";
                    cin >> choice;
                    if (choice == "yes") {
                        string outputImageName;
                        cout << "Please enter name to your new image to store\n";
                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                        cin >> outputImageName;
                        imageEdit.saveImage(outputImageName);
                        cout << "Saved Successfully." << endl ;
                        // Code to save the image with the given filename
                        cout << "Image saved as " << outputImageName << endl;
                    } else if (choice == "no") {
                        cout << "Image not saved." << endl;
                    } else {
                        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
                    }

                    cout << "\nSuccessfuly Editing.\n" << endl;
                    break;
                }
                else
                {
                    cout << "\nFalid Editing.\n" << endl;
                    break;
                }

            }
            else if (image1.width < image2.width && image1.height > image2.height)
            {
                Image imageEdit(image1.width,image2.height);
                for (int i = 0; i < imageEdit.width; ++i)
                {
                    for (int j = 0; j < imageEdit.height; ++j)
                    {
                        for (int k = 0; k < 3; ++k)
                        {
                            imageEdit(i,j,k) = (image1(i,j,k) + image2(i,j,k)) / 2;
                        }
                    }
                }
                if (imageEdit.saveImage(img1))
                {
                    imageEdit.saveImage(img1);
                    string  choice , outputImageName;
                    cout << "\nSuccessfuly Editing.\n" << endl;
                    cout << "Image processed successfully." << endl;
                    cout << "Do you want to store the image? (yes/no): ";
                    cin >> choice;
                    if (choice == "yes") {
                        string outputImageName;
                        cout << "Please enter name to your new image to store\n";
                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                        cin >> outputImageName;
                        imageEdit.saveImage(outputImageName);
                        cout << "Saved Successfully." << endl ;
                        // Code to save the image with the given filename
                        cout << "Image saved as " << outputImageName << endl;
                    } else if (choice == "no") {
                        cout << "Image not saved." << endl;
                    } else {
                        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
                    }
                    break;
                }
                else
                {
                    cout << "\nFalid Editing.\n" << endl;
                    break;
                }
            }
            else if (image1.width > image2.width && image1.height < image2.height)
            {
                Image imageEdit(image2.width,image1.height);
                for (int i = 0; i < image1.width; ++i)
                {
                    for (int j = 0; j < image2.height; ++j)
                    {
                        for (int k = 0; k < 3; ++k)
                        {
                            imageEdit(i,j,k) = (image1(i,j,k) + image2(i,j,k)) / 2;
                        }
                    }
                }
                if (imageEdit.saveImage(img1))
                {
                    imageEdit.saveImage(img1);
                    string  choice , outputImageName;
                    cout << "\nSuccessfuly Editing.\n" << endl;
                    cout << "Image processed successfully." << endl;
                    cout << "Do you want to store the image? (yes/no): ";
                    cin >> choice;
                    if (choice == "yes") {
                        string outputImageName;
                        cout << "Please enter name to your new image to store\n";
                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                        cin >> outputImageName;
                        imageEdit.saveImage(outputImageName);
                        cout << "Saved Successfully." << endl ;
                        // Code to save the image with the given filename
                        cout << "Image saved as " << outputImageName << endl;
                    } else if (choice == "no") {
                        cout << "Image not saved." << endl;
                    } else {
                        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
                    }
                    break;
                }
                else
                {
                    cout << "\nFalid Editing.\n" << endl;
                    break;
                }
            }
            else if (image1.width > image2.width && image1.height > image2.height)
            {
                Image imageEdit(image2.width,image2.height);
                for (int i = 0; i < imageEdit.width; ++i)
                {
                    for (int j = 0; j < imageEdit.height; ++j)
                    {
                        for (int k = 0; k < 3; ++k)
                        {
                            imageEdit(i,j,k) = (image1(i,j,k) + image2(i,j,k)) / 2;
                        }
                    }
                }
                if (imageEdit.saveImage(img1))
                {
                    imageEdit.saveImage(img1);
                    string  choice , outputImageName;
                    cout << "\nSuccessfuly Editing.\n" << endl;
                    cout << "Image processed successfully." << endl;
                    cout << "Do you want to store the image? (yes/no): ";
                    cin >> choice;
                    if (choice == "yes") {
                        string outputImageName;
                        cout << "Please enter name to your new image to store\n";
                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                        cin >> outputImageName;
                        imageEdit.saveImage(outputImageName);
                        cout << "Saved Successfully." << endl ;
                        // Code to save the image with the given filename
                        cout << "Image saved as " << outputImageName << endl;
                    } else if (choice == "no") {
                        cout << "Image not saved." << endl;
                    } else {
                        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
                    }
                    break;
                }
                else
                {
                    cout << "\nFalid Editing.\n" << endl;
                    break;
                }
            }

            else
            {
                Image imageEdit(image1.width,image1.height);
                for (int i = 0; i < imageEdit.width; ++i)
                {
                    for (int j = 0; j < imageEdit.height; ++j)
                    {
                        for (int k = 0; k < 3; ++k)
                        {
                            imageEdit(i,j,k) = (image1(i,j,k) + image2(i,j,k)) / 2;
                        }
                    }
                }
                if (imageEdit.saveImage(img1))
                {
                    imageEdit.saveImage(img1);
                    string  choice , outputImageName;
                    cout << "\nSuccessfuly Editing.\n" << endl;
                    cout << "Image processed successfully." << endl;
                    cout << "Do you want to store the image? (yes/no): ";
                    cin >> choice;
                    if (choice == "yes") {
                        string outputImageName;
                        cout << "Please enter name to your new image to store\n";
                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                        cin >> outputImageName;
                        imageEdit.saveImage(outputImageName);
                        cout << "Saved Successfully." << endl ;
                        // Code to save the image with the given filename
                        cout << "Image saved as " << outputImageName << endl;
                    } else if (choice == "no") {
                        cout << "Image not saved." << endl;
                    } else {
                        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
                    }
                    break;
                }
                else
                {
                    cout << "\nFalid Editing.\n" << endl;
                    break;
                }
            }
        }
        catch (const exception& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
}




void Blurring() {
    string filename;
    cout << "Please enter colored image name here: ";
    cin >> filename;

    Image normal_image(filename);

    int width = normal_image.width;
    int height = normal_image.height;

    int kernelSize = 27;
    Image blurredImage(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;
            for (int ky = -kernelSize/2; ky <= kernelSize/2; ++ky) {
                for (int kx = -kernelSize/2; kx <= kernelSize/2; ++kx) {
                    int nx = x + kx;
                    int ny = y + ky;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        unsigned char& red = normal_image.getPixel(nx, ny, 0);
                        unsigned char& green = normal_image.getPixel(nx, ny, 1);
                        unsigned char& blue = normal_image.getPixel(nx, ny, 2);
                        sumR += red;
                        sumG += green;
                        sumB += blue;
                        count++;
                    }
                }
            }
            int avgR = sumR / count;
            int avgG = sumG / count;
            int avgB = sumB / count;
            blurredImage.setPixel(x, y, 0, avgR);
            blurredImage.setPixel(x, y, 1, avgG);
            blurredImage.setPixel(x, y, 2, avgB);
        }
    }

    cout << "Image blurred successfully!" << endl;
    string choice;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        string filenamee;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filenamee;
        blurredImage.saveImage(filenamee);
        cout << "Image saved as " << filenamee << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }
}




void RotateImage() {
    int Angle;
    cout << "Enter the Angle of Rotation: ";
    cin >> Angle;


    string filename;
    cout << "Please enter image name here: ";
    cin >> filename;

    Image normal_image(filename);

    int width = normal_image.width;
    int height = normal_image.height;

    // Create a new image with rotated dimensions
    Image RotatedImage(height, width);
    Image rotated180(width, height);
    Image rotated270(height, width);
    if (Angle == 90) {
        // Rotate the image by 90 degrees
        for (int i = 0; i < height; i++) {
            for (int k = 0; k < width; k++) {
                int rotatedX = height - 1 - i;
                int rotatedY = k;

                for (int channel = 0; channel < 3; ++channel) {
                    RotatedImage.setPixel(rotatedX, rotatedY, channel, normal_image.getPixel(k, i, channel));
                }
            }
        }
    } else if (Angle == 180) {

        for (int i = 0; i < normal_image.width; i++) {
            for (int j = 0; j < normal_image.height; j++) {
                for (int k = 0; k < 3; ++k) {
                    rotated180(i, j, k) = normal_image(normal_image.width - 1 - i, normal_image.height - 1 - j, k);
                }
            }
        }

    }else if (Angle == 270) {
        for (int i = 0; i < height; i++) {
            for (int k = 0; k < width; k++) {
                int rotatedX = height - 1 - i;
                int rotatedY = k;

                for (int channel = 0; channel < 3; ++channel) {
                    rotated270.setPixel(rotatedX, rotatedY, channel, normal_image.getPixel(k, i, channel));
                }
            }
        }

        for (int i = 0; i < rotated270.width / 2; i++) {
            for (int j = 0; j < rotated270.height; j++) {
                for (int k = 0; k < 3; k++) {
                    unsigned int temp = rotated270(i, j, k);
                    rotated270(i, j, k) = rotated270(rotated270.width - 1 - i, j, k);
                    rotated270(rotated270.width - 1 - i, j, k) = temp;
                }
            }
        }
    }


    cout << "Image Rotated successfully!" << endl;
        string choice;
        cout << "Do you want to store the image? (yes/no): ";
        cin >> choice;

        if (choice == "yes") {
            if (Angle==90)
            {
                string rotatedImageName;
                cout << "Please enter name for your rotated image: ";
                cin >> rotatedImageName;

                RotatedImage.saveImage(rotatedImageName);
                cout << "Image saved as " << rotatedImageName << endl;
            }
            else if (Angle==180)
            {
                string rotatedImageName;
                cout << "Please enter name for your rotated image: ";
                cin >> rotatedImageName;

                rotated180.saveImage(rotatedImageName);
                cout << "Image saved as " << rotatedImageName << endl;
            }
            else if (Angle == 270){

                string rotatedImageName;
                cout << "Please enter name for your rotated image: ";
                cin >> rotatedImageName;

                rotated270.saveImage(rotatedImageName);
                cout << "Image saved as " << rotatedImageName << endl;
            }
        } else if (choice == "no") {
            cout << "Image not saved." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
}



void AddingFrame(){

    string filename;
    cout << "Please enter image name here: ";
    cin >> filename;
    
    Image image(filename);

    int height = image.height;
    int width  = image.width;
    char type;
    cout  << "For fancy frame enter f or normal n: ";
    cin >> type;

 // blue right bar
    for (int i = width - 11; i < width ; ++i) {
        for (int j = 0; j < height ; ++j) {

             image(i,j,0) =0;
             image(i,j,1) =0;
             image(i,j,2) =255;
            }
        }
// blue top bar
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < 10; ++j) {


            image(i,j,0) =0;
            image(i,j,1) =0;
            image(i,j,2) =255;
        }
    }

//blue left bar
    for (int i = 0; i < 10 ; i++) {
        for (int j = 0; j < height ; j++) {

            image(i,j,0) =0;
            image(i,j,1) =0;
            image(i,j,2) =255;
        }
    }

    //blue bottom bar
    for (int j = 0; j < width ; j++) {
       for (int i = height - 11; i < height ; i++)
       {
            image(j,i,0) =0;
            image(j,i,1) =0;
            image(j,i,2) =255;
        }
    }

//adding white frames
    if (type == 'f' or type == 'F') {

        // Right first white bar
        for (int i = 11; i < height - 13; i++) {
            for (int j = width - 14; j < width - 11; j++) {
                image(j, i, 0) = 255;
                image(j, i, 1) = 255;
                image(j, i, 2) = 255;
            }
        }

// Left first white bar
        for (int i = 11; i < 14; i++) {
            for (int j = 11; j < height - 13; j++) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }

// upper first white bar
        for (int i = 11; i < width - 11; ++i) {
            for (int j = 11; j <= 13; ++j) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }

// Bottom first white line
        for (int j = 11; j < width - 11 ; j++) {
            for (int i = height - 15; i <= height - 13; i++) {
                image(j, i, 0) = 255;
                image(j, i, 1) = 255;
                image(j, i, 2) = 255;
            }
        }
        
// Inner white frame
       // Right inner white bar
        for (int i = 20; i < height - 22; i++) {
            for (int j = width - 24; j < width - 20; j++) {
                image(j, i, 0) = 255;
                image(j, i, 1) = 255;
                image(j, i, 2) = 255;
            }
        }

        //left inner white bar
        for (int i = 20; i < 23; i++) {
            for (int j = 19; j < height - 20; j++) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }

        //upper inner white bar
        for (int i = 20; i < width - 20; ++i) {
            for (int j = 19; j <= 21; ++j) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
        //bottom inner white bar
        for (int j = 21; j < width - 20 ; j++) {
            for (int i = height - 23; i <= height - 21; i++) {
                image(j, i, 0) = 255;
                image(j, i, 1) = 255;
                image(j, i, 2) = 255;
            }
        }
}


    cout << "Image framed successfully!" << endl;
    string choice;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        string filenamee;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filenamee;
        image.saveImage(filenamee);
        cout << "Image saved as " << filenamee << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }
    }


void ToPurple()
{
    string filename;
    cout << "Please enter image name here: ";
    cin >> filename;
    Image image(filename);

    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {

            int Rval = image(j, i, 0);
            int Gval = image(j, i, 1);
            int Bval = image(j, i, 2);

            // Increase red and blue, decrease green
            Rval += 33;
            Bval += 26;
            Gval -= 22;

            // Ensure color values stay within the valid range (0-255)
            Rval = min(255, max(0, Rval));
            Gval = min(255, max(0, Gval));
            Bval = min(255, max(0, Bval));

            // Assign the adjusted values back to the image
            image(j, i, 0) = Rval;
            image(j, i, 1) = Gval;
            image(j, i, 2) = Bval;
        }
    }



    cout << "Image colored successfully!" << endl;
    string choice;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        string filenamee;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filenamee;
        image.saveImage(filenamee);
        cout << "Image saved as " << filenamee << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }
}



void Infra_Red()
{
    string filename;
    cout << "Please enter image name here: ";
    cin >> filename;
    Image image(filename);

    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            image( j , i , 0) = 255;
                int GVal =  image( j , i , 1);
                image( j , i , 1) = 255 - image( j , i , 2);
                image( j , i , 2) = 255 - GVal;

        }
    }

    cout << "Image colored successfully!" << endl;
    string choice;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        string filenamee;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filenamee;
        image.saveImage(filenamee);
        cout << "Image saved as " << filenamee << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }
}



void SunLight()
{
    string filename;
    cout << "Please enter image name here: ";
    cin >> filename;
    Image image(filename);

    for (int i = 0; i < image.height ; ++i) {
        for (int j = 0; j <image.width ; ++j) {

            int R = image( j , i , 0) ;
            int G = image( j , i , 1) ;
            int B = image( j , i , 2) ;

            R += 45;
            G += 63;

            if (R > 255) R = 255;
            if (G > 255) G = 255;
            if (B > 255) B = 255;

            image( j , i , 0) = R;
             image( j , i , 1) = G;
             image( j , i , 2) = B;
        }
    }

    cout << "Image colored successfully!" << endl;
    string choice;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        string filenamee;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filenamee;
        image.saveImage(filenamee);
        cout << "Image saved as " << filenamee << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }
}



void cropImage() {
    int x, y, width, height;
    string imageName;
    cout << "enter the name of the image: ";
    cin >> imageName;

    Image originalImage(imageName);
    cout << "Your image dimensions are: " << originalImage.width << " (width pixels) " << "x " << originalImage.height << " (height pixels)" <<  endl;

    cout << "enter the horizontal starting coordinate: ";
    cin >> x;
    cout << "enter the vertical starting coordinate: ";
    cin >> y;
    cout << "enter the width which you want to crop: ";

    cin >> width;
    cout << "enter the height which you want to crop: ";
    cin >> height;

    if (x >= 0 && y >= 0 && width > 0 && height > 0 &&
        x + width <= originalImage.width && y + height <= originalImage.height) {
        Image croppedImage(width, height);

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                for (int k = 0; k < 3; k++) {
                    croppedImage(i, j, k) = originalImage(x + i, y + j, k);
                }
            }
        }

        cout << "Image cropped successfully!" << endl;
        string choice;
        cout << "Do you want to store the image? (yes/no): ";
        cin >> choice;

        if (choice == "yes") {
            string filenamee;
            cout << "Please enter name to your new image to store\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
            cin >> filenamee;
            croppedImage.saveImage(filenamee);
            cout << "Image saved as " << filenamee << endl;
        } else if (choice == "no") {
            cout << "Image not saved." << endl;
        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }
    }
}


void resizeImage()
{
    string name, newName;
    float ratio;

    cout<<"enter the name of the image: ";
    cin>>name;

    Image image(name);
    cout<<"your image dimensions: "<<image.width<<"x"<<image.height<<endl;

    string choice;
    cout<<"1) enter new dimensions\n2) enter reduction or increase ratio\n";
    cin>>choice;

    if (choice == "1")
    {
        int newWidth, newHeight;
        cout<<"enter the new width: ";
        cin>>newWidth;
        cout<<"enter the new height: ";
        cin>>newHeight;

        Image resizedImage(newWidth, newHeight);

        for (int i = 0 ; i < newHeight ; i++)
        {
            for (int j = 0 ; j < newWidth ; j++)
            {
                for (int k = 0 ; k < 3 ; k++)
                {
                    float pxl_hor_1 = float(j) / newWidth * image.width;
                    float pxl_vir_1 = float(i) / newHeight * image.height;
                    int pxl_hor_2 = round(pxl_hor_1);
                    int pxl_vir_2 = round(pxl_vir_1);
                    resizedImage(j, i, k) = image(pxl_hor_2, pxl_vir_2, k);
                }
            }
        }

        string choice;
        cout << "Do you want to store the image? (yes/no): ";
        cin >> choice;

        if (choice == "yes") {
            string filenamee;
            cout << "Please enter name to your new image to store\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
            cin >> filenamee;
            resizedImage.saveImage(filenamee);
            cout << "Image saved as " << filenamee << endl;
        } else if (choice == "no") {
            cout << "Image not saved." << endl;
        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }

    }
    else if (choice == "2")
    {
        cout<<"enter the ratio: ";
        cin>>ratio;

        int newWidth = round(image.width * ratio);
        int newHeight = round(image.height * ratio);

        Image resizedImage(newWidth, newHeight);

        for (int i = 0 ; i < newHeight ; i++)
        {
            for (int j = 0 ; j < newWidth ; j++)
            {
                for (int k = 0 ; k < 3 ; k++)
                {
                    float pxl_hor_1 = float(j) / newWidth * image.width;
                    float pxl_vir_1 = float(i) / newHeight * image.height;
                    int pxl_hor_2 = round(pxl_hor_1);
                    int pxl_vir_2 = round(pxl_vir_1);
                    resizedImage(j, i, k) = image(pxl_hor_2, pxl_vir_2, k);
                }
            }
        }
        cout << "Image resizing completed successfully!" << endl;
        string choice;
        cout << "Do you want to store the image? (yes/no): ";
        cin >> choice;

        if (choice == "yes") {
            string filenamee;
            cout << "Please enter name to your new image to store\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
            cin >> filenamee;
            resizedImage.saveImage(filenamee);
            cout << "Image saved as " << filenamee << endl;
        } else if (choice == "no") {
            cout << "Image not saved." << endl;
        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }
    }
}



void DetectEdges() {
    string name;
    cout<<"enter the name of the image: ";
    cin>>name;
    Image image(name);
    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;

            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, avg);
            }

            int gx = image.getPixel(i - 1, j - 1, 0) - image.getPixel(i + 1, j - 1, 0) +
                     2 * image.getPixel(i - 1, j, 0) - 2 * image.getPixel(i + 1, j, 0) +
                     image.getPixel(i - 1, j + 1, 0) - image.getPixel(i + 1, j + 1, 0);

            int gy = image.getPixel(i - 1, j - 1, 0) + 2 * image.getPixel(i, j - 1, 0) +
                     image.getPixel(i + 1, j - 1, 0) - image.getPixel(i - 1, j + 1, 0) -
                     2 * image.getPixel(i, j + 1, 0) - image.getPixel(i + 1, j + 1, 0);
            int magnitude = sqrt(gx * gx + gy * gy);
            if (magnitude >= 127) {
                image.setPixel(i, j, 0, 255);
                image.setPixel(i, j, 1, 255);
                image.setPixel(i, j, 2, 255);
            } else {
                image.setPixel(i, j, 0, 0);
                image.setPixel(i, j, 1, 0);
                image.setPixel(i, j, 2, 0);
            }
        }
    }

    cout << "Image processing completed successfully!" << endl;
    string choice;
    cout << "Do you want to store the image? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        string filenamee;
        cout << "Please enter name to your new image to store\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filenamee;
        image.saveImage(filenamee);
        cout << "Image saved as " << filenamee << endl;
    } else if (choice == "no") {
        cout << "Image not saved." << endl;
    } else {
        cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
    }

}



void display_menu() {
       cout << "1-Grayscale filter." << endl;
       cout << "2-Black and white filter." << endl;
       cout << "3-Invert image filter." << endl;
       cout << "4-Merging two images filter." << endl;
       cout << "5-Flip image filter." << endl;
       cout << "6-Rotate image filter." << endl;
       cout << "7-Darken and Lighten image filter." << endl;
       cout << "8-Crop image filter." << endl ;
       cout << "9-Add frame filter." << endl;
       cout << "10-DetectEdges()" << endl ;
       cout << "11-Resize image filter." << endl ;
       cout << "12-Blur image filter." << endl;
       cout << "13-Purple image filter." << endl ;
       cout << "14-Infra-Red image filter." << endl ;
       cout << "15-Sunlight filter." << endl ;
       cout << "0-To exit." << endl;
       cout << "Enter here: ";
}


int main() {
    int choice;
    bool first_time = true;

    while (true) {
        if (first_time) {
            cout << "Hello, you can choose between 15 image filters." << endl;
            cout << "Choose between 1:15 or 0 to exit" << endl;
            first_time = false;
        }

        display_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                ConvertToGrayScale();
                break;
            case 2:
                Black_and_White();
                break;
            case 3:
                Invert();
                break;
            case 4:
                MergeImages();
                break;
            case 5:
                FlipImage();
                break;
            case 6:
                RotateImage();
                break;
            case 7:
                AdjustImageBrightness();
                break;
            case 8:
                cropImage();
                break;
            case 9:
                AddingFrame();
                break;
            case 10:
                DetectEdges();
                break;
            case 11:
                resizeImage();
                break;
            case 12:
                Blurring();
                break;
            case 13:
                ToPurple();
                break;
            case 14:
                Infra_Red();
                break;
            case 15:
                SunLight();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}