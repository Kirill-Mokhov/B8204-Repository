#include<iostream>
#include<locale>

using namespace std;

class Product{
private:
    unsigned int price = 0;

public:
    Product(unsigned int p){
        price = p;
    }

    unsigned int get_price(){
        return this->price;
    }
};

class Tool: public Product{
private:
    string type = "None";

public:
    Tool(unsigned int p, string t): Product(p){
        type = t;
    }
};

class Food: public Product{
private:
    unsigned int caloricity = 0;

public:
    Food(unsigned int p, unsigned int c): Product(p){
        caloricity = c;
    }
};

class Basket{
private:
    unsigned int price = 0;
public:
    void add(Product item){
        cout << "Товар добавлен в корзину!" << endl;
        this->price += item.get_price();
    }
    unsigned int get_price(){
        return this->price;
    }
};

class Shop{
public:
    void main_menu(){
        system("cls");
        cout << "Добро пожаловать в магазин \"Магазин\"!\n" << endl;
        cout << R"(___  ___  ___  _____   ___   ___________ _   _
|  \/  | / _ \|  __ \ / _ \ |___  /_   _| \ | |
| .  . |/ /_\ \ |  \// /_\ \   / /  | | |  \| |
| |\/| ||  _  | | __ |  _  |  / /   | | | . ` |
| |  | || | | | |_\ \| | | |./ /____| |_| |\  |
\_|  |_/\_| |_/\____/\_| |_/\_____/\___/\_| \_/
                                              )" << endl;
        cout << "1. Купить еду" << endl;
        cout << "2. Купить инструменты" << endl;
        cout << "3. Цена корзины" << endl;
        cout << "0. Покинуть магазин" << endl;
    }

    void food_menu(){
        system("cls");
        cout << "Продуктовый отдел\n" << endl;
        cout << R"( ___________  ___
|  ___|  _  \/ _ \
| |__ | | | / /_\ \
|  __|| | | |  _  |
| |___| |/ /| | | |
\____/|___/ \_| |_/
                                              )" << endl;
        cout << "1. Купить ломтик июльского неба (13 руб)" << endl;
        cout << "2. Купить леденцы на палочке (20 руб)" << endl;
        cout << "0. В главный отдел" << endl;
    }

    void tool_menu(){
        system("cls");
        cout << "Отдел инструментов\n" << endl;
        cout << R"(  _____    __  __  _____  __                 __    __  _____
  \_   \/\ \ \/ _\/__   \/__\/\ /\  /\/\    /__\/\ \ \/__   \/\_/\
   / /\/  \/ /\ \   / /\/ \// / \ \/    \  /_\ /  \/ /  / /\/\_ _/
/\/ /_/ /\  / _\ \ / / / _  \ \_/ / /\/\ \//__/ /\  /  / /    / \
\____/\_\ \/  \__/ \/  \/ \_/\___/\/    \/\__/\_\ \/   \/     \_/
                                              )" << endl;
        cout << "1. Купить Mind Eraser 3000 (3000 руб)" << endl;
        cout << "2. Купить бластер пришельцев (1200 руб)" << endl;
        cout << "0. В главный отдел" << endl;
    }

};

int main(){
    int choice = -1;
    Shop shop;
    Basket basket;

    Food slice_of_the_July_sky(13, 1000);
    Food lollipops(20, 2000);

    Tool mind_eraser_3000(3000, "Secret Type");
    Tool alien_blaster(1200, "Weapon");

    setlocale(LC_ALL,"Russian");

    shop.main_menu();
    while(choice != 0){
        cin >> choice;
        switch(choice){
        case 1:
            shop.food_menu();
            while(choice != 0){
                cin >> choice;
                switch(choice){
                case 1:
                    basket.add(slice_of_the_July_sky);
                    break;
                case 2:
                    basket.add(lollipops);
                    break;
                }
            }
            shop.main_menu();
            choice = -1;
            break;
        case 2:
            shop.tool_menu();
            while(choice != 0){
                cin >> choice;
                switch(choice){
                case 1:
                    basket.add(mind_eraser_3000);
                    break;
                case 2:
                    basket.add(alien_blaster);
                    break;
                }
            }
            shop.main_menu();
            choice = -1;
            break;
        case 3:
            cout << "Цена товаров в вашей корзине: " << basket.get_price() << endl;
            break;
        }
    }

}
