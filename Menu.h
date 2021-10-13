#ifndef MENU_H
#define MENU_H
using namespace std ;

class Menu
{
    private:
        int itemNum ;
        string item ;
        double price ;
        int quantity ;

    public:
        Menu(int, string, double, int = 0) ;
        ~Menu() {}

        int getItemNum() ;
        string getItem() ;
        double getPrice() ;
        int getQuantity() ;

        void setItemNum(int) ;
        void setItem(string) ;
        void setPrice(double) ;
        void setQuantity(int) ;
} ;

#endif