#include <iostream>
#include "Menu.h"
using namespace std ;

Menu::Menu(int newItemNum, string newItem, double newPrice, int newQuantity)
{
    setItemNum(newItemNum) ;
    setItem(newItem) ;
    setPrice(newPrice) ;
    setQuantity(newQuantity) ;
}

int Menu::getItemNum()
    { return itemNum ; }

string Menu::getItem()
    { return item ; }

double Menu::getPrice()
    { return price ; }

int Menu::getQuantity()
    { return quantity ; }


void Menu::setItemNum(int newItemNum)
    { itemNum = newItemNum ; }

void Menu::setItem(string newItem)
    { item = newItem ; }

void Menu::setPrice(double newPrice)
    { price = newPrice ; }

void Menu::setQuantity(int newQuantity)
    { quantity = newQuantity ; }

