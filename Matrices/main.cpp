#include <iostream>

class MatrixPlus{
    private: 
        int height;
        int width;
        int **Mx;
    public:
        MatrixPlus(int h, int w){
            height = h;
            width = w;
            Mx = new int*[width];
            for(int i = 0; i < width; i++)
                Mx[i] = new int[height];
        }
        
        int getHeight();
        int getWidth();
        void displayMatrix();
        void manualInput();
};

int MatrixPlus::getHeight(){
    return height;
}

int MatrixPlus::getWidth(){
    return width;
}

void MatrixPlus::displayMatrix(){
    for(int i = 0 ; i < width; i++){
        for(int j = 0; j < height; j++){
            std::cout<<Mx[i][j];
        }
        std::cout<<std::endl;
    }
}

void MatrixPlus::manualInput(){
    for(int i = 0 ; i < width; i++){
        for(int j = 0; j < height; j++){
            std::cout<<"x: "<< i <<" | "<< "y: " << j;
            std::cout<<std::endl;
            std::cin>>Mx[i][j];
        }
    }
    std::cout<<std::endl;
}

int main()
{
    MatrixPlus m1(2, 2);
    
    m1.manualInput();
    
    m1.displayMatrix();

    return 0;
}
