//---------------------------------------------------------------------------

#ifndef UPuntoH
#define UPuntoH
//---------------------------------------------------------------------------
class Punto{

        private:
        //Atributos
        int x,y;
        TColor color;


        public:
        //Constructores
        Punto(){
                this->x=0;
                this->y=0;
                this->color=clBlack;
        };
        
        Punto(int x, int y, TColor color){
                this->x=x;
                this->y=y;
                this->color=color;
        };

        //Destructora


        //Getters
        int getX(){
                return(this->x);
        };
        int getY(){
                return(this->y);
        };
        TColor getColor(){
                return(this->color);
        };

        //Setters
        void setCoordenadas(int x,int y){
                this->x=x;
                this->y=y;
        };
        void setColor(TColor color){
                this->color=color;
        };

};
#endif

