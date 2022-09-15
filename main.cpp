#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>

using namespace cv;
using namespace std;

Mat crearImagenEnergia(Mat &img)
{
    Mat imgEnergia;
    // obtener el numero de filas y columnas de la img original
    int filas = img.rows;
    int cols = img.cols;

    // inicializar mapa de energia con ceros
    imgEnergia = Mat::zeros(filas, cols, CV_8UC1);

    // recorrer y CALCULAR ENERGIA DE C/PIXEL de img original
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            // pixeles
            Vec3b pixel = img.at<Vec3b>(i, j);  // Aqui esta mal el numero de canañes eb
            Vec3b pixelBefore, pixelAfter, pixelTop, pixelBottom, pixelFake;

            // canales
            uchar R, G, B, R1, G1, B1, R2, G2, B2, R3, G3, B3, R4, G4, B4;
            B = pixel[0];
            G = pixel[1];
            R = pixel[2];

            // For Gx
            pixelBefore = img.at<Vec3b>(i-1, j);
            pixelAfter =  img.at<Vec3b>(i+1, j);
            // For Gy
            pixelBottom = img.at<Vec3b>(i, j-1);
            pixelTop =  img.at<Vec3b>(i, j+1);

            // For Gx
            B1 = pixelBefore[0];
            G1 = pixelBefore[1];
            R1 = pixelBefore[2];
            B2 = pixelAfter[0];
            G2 = pixelAfter[1];
            R2 = pixelAfter[2];
            // For Gy
            B3 = pixelBottom[0];
            G3 = pixelBottom[1];
            R3 = pixelBottom[2];
            B4 = pixelTop[0];
            G4 = pixelTop[1];
            R4 = pixelTop[2];

            // Calculate Gx² = Rx² + Gx² + Bx²
            auto Gx_2 = pow(R2 - R1,2) +pow(G2 - G1,2) + pow(B2 - B1,2);
//            cout << "Gx² = " << Gx_2 << endl;
            // Calculate Gy² = Ry² + Gy² + By²
            auto Gy_2 = pow(R4 - R3,2) +pow(G4 - G3,2) + pow(B4 - B3,2);
//            cout << "Gy² = " << Gy_2 << endl;
            // Calculate sqrt (Gx² + Gy²)
            auto energyPixel = sqrt(Gx_2 + Gy_2);
//            cout << "energyPixel = " << energyPixel << endl;

            // Añadir a mapa de bordes
            imgEnergia.at<uchar>(i, j) = energyPixel ;
        }
    }

    // mostrar imagen
    namedWindow("Original - Mapa de Bordes", WINDOW_AUTOSIZE);
    imshow("Original - Mapa de Bordes", imgEnergia);

    return  imgEnergia;
}

// Adaptación de Dijkstra
vector <uchar> dijkstra (char direccionCostura, Mat &imgEnergia)
{
     // cálculo de las filas y columnas de la img
    int filas = imgEnergia.rows;
    int cols = imgEnergia.cols;

    if (direccionCostura == 'v')
    {
        cout << "Costura vertical" << endl;
        for (size_t i = 0; i < filas; i++) {
            for (size_t j = 0; j < cols; j++) {
                // Seleccionar la primera fila

            }
        }
    }
    else if (direccionCostura == 'h')
    {
        cout << "Costura horizontal" << endl;
    }

}
// Encontrar costura
//vector <uchar> encontrarCostura(bool orientacion, Mat img){}

int main()
{
    // Seleccionar imagen
    string filename;
    filename = "../img/aqp.png";
    Mat IMG = imread(filename);

    // Mostrar imagen
    namedWindow("Original", WINDOW_AUTOSIZE);
    imshow("Original", IMG);

    //Proceso de cálculo
    crearImagenEnergia(IMG);

    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;
}