#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "patternh.h"
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;
////////////////////

enum class skinColor : int
{
    Black,
    Yellow,
    White,
    Unknown
};
enum class DanceEnum : int
{
    Tango,
    Disko,
    HipHop,

    Tverk,

    None
};

class DanceStrategy{
public:
    virtual ~DanceStrategy(){}
    virtual void dance() = 0;
};

class TangoDanceStrategy : public DanceStrategy
{
    void dance() {cout << "tango tango tango";}
};
class DiskoDanceStrategy : public DanceStrategy
{
    void dance() {cout << "disko disko partizany";}
};
class HipHopDanceStrategy : public DanceStrategy
{
    void dance() {cout << "hip hop dance";}
};
class TverkDanceStraty : public DanceStrategy
{
    void dance() {cout << "Tverk yep)";}
};

DanceStrategy *CreateDanceStrategy(DanceEnum danceManner)
 {
   switch(danceManner)
   {
     case DanceEnum::Tango: return new TangoDanceStrategy;
     case DanceEnum::Disko: return new DiskoDanceStrategy;
     case DanceEnum::HipHop: return new HipHopDanceStrategy;

     // Новый способ (для варианта 2)
     case DanceEnum::Tverk: return new TverkDanceStraty;

     default: return nullptr;
   }
 }

class Woman {
private:
    int weight;
    skinColor colorHair;
    //bool children;
    DanceStrategy *danceManner;

    void DoDanceUsingStrategy() {
        if(danceManner == nullptr)
        {
            cout << "Do nothing!";
            return;
        }
        else
        {
            danceManner -> dance();
        }
    }
    void DetectedChildren()
    {
        if(haveChildren()){
            cout << "mama";
        }
        else{
            cout << "no mama";
        }
    }

protected:
    bool children;

public:
    //bool haveChildren() const { return children; }
    skinColor GetColor() const { return colorHair; }

    int GetWaight() const {return weight;}


    virtual void printType() = 0;

    virtual void Peel() = 0;
    //Woman(int h, string m, int s);
    Woman(skinColor color) :weight(55), colorHair(color), height(165), children(true), danceManner(nullptr){
        children = static_cast<bool>(rand() % 2);
    }
    ~Woman() {
        if (danceManner != nullptr) delete danceManner;
    };

public:
    int height;

    bool haveChildren() const { return children; }

    //virtual void dance() = 0;
    virtual void walk()
    {
        if (haveChildren())
        {
            cout << "I go walk WITH children ";
        }
        else
        {
            cout << "I go walk WITHOUT children ";
        }
    }
    void dance() {
        /////////////////////////////////
        /////////////////////////////////
        /////////////////
        ///////////////
        ///////////////
        printType();
        cout << " : ";
        DetectedChildren();
        cout << " : ";

        walk();
        cout << " : ";
        DoDanceUsingStrategy();
        cout << endl;
    }
     void SetDanceManner(DanceStrategy *DancManner)
    {
      danceManner = DancManner;
    };

};


class youngirl : public Woman {
public:
    youngirl() : Woman(skinColor::Black) { SetDanceManner(CreateDanceStrategy(DanceEnum::Tango)); }
    //youngirl();//: Woman(1, "green",3233), milkteeht(2) { cout << "young woman create" << endl; }
    ~youngirl() { }
    //void walk() override;
    void printType(){cout << "youngirl";}
    void Peel() {cout << "peeeeel";}
};

/*void youngirl::walk()
{

    Woman::walk(); // Вызов функции, определенной в базовом классе
    cout << "young girl is walk" << endl;
}*/

class oldWoman : public Woman {
protected:
    bool dementia;
public:

    //void walk() override;
    oldWoman() : Woman(skinColor::White) { SetDanceManner(CreateDanceStrategy(DanceEnum::HipHop)); }

    //oldWoman() : Woman(skinColor::White) { };//: Woman(75, "black", 175), dementia(false) { cout << "grangma create" << endl; }
    ~oldWoman() { }
    void printType(){cout << "oldWoman";}
    void Peel() {cout << "prrrrl";}
};

/*void oldWoman::walk()
{
    Woman::walk(); // Вызов функции, определенной в базовом классе
    cout << "old woman is walk" << endl;
}*/

class normalWoman : public Woman {
protected:
    int countChildren;
public:
    normalWoman() : Woman(skinColor::Black) { SetDanceManner(CreateDanceStrategy(DanceEnum::Disko)); }

    //normalWoman() : Woman(skinColor::Yellow) { };// : Woman(76, "black", 170), countChildren(2) { }//cout << "woman create" << endl; }
    ~normalWoman() {}// cout << "woman delete" << endl; }
    //void walk() override;
    void printType(){cout << "normalWoman";}
    void Peel() {cout << "paaaal";}
};
/*void normalWoman::walk()
{
    Woman::walk(); // Вызов функции, определенной в базовом классе
    cout << "normal woman is walk" << endl;
}*/

enum class WomanType : int
{
    normalWoman = 1,
    oldWoman = 2,
    youngirl = 3,

    Undefined = 0

};

Woman* createWoman(WomanType i) {

    Woman* newWoman = nullptr;

    if (i == WomanType::youngirl) {
        newWoman = new youngirl;

    }
    else if (i == WomanType::oldWoman) {
        newWoman = new oldWoman;
    }
    else if (i == WomanType::normalWoman) {
        newWoman = new normalWoman;
    }
    return newWoman;
}

void AllGetMoney(Iterator<Woman*>* it)
{
    for (it->First(); !it->IsDone(); it->Next())
    {
        Woman* currentWoman = it->GetCurrent();
        currentWoman->walk();
    }
}
//////////////////////////
void DanceEmAll(Iterator<Woman*> *it)
 {
     for(it->First(); !it->IsDone(); it->Next())
     {
         Woman *currentWoman = it->GetCurrent();
         currentWoman->dance();
     }
 }

 // Функция, позволяющая "съесть" только хорошие фрукты
 // (демонстрация решения проблемы "в лоб")
 void DanceEmAllGood(Iterator<Woman*> *it)
 {
     for(it->First(); !it->IsDone(); it->Next())
     {
         Woman *currentWoman = it->GetCurrent();
         if(!currentWoman->haveChildren()) continue;

         currentWoman->dance();
     }
 }

 // Функция, позволяющая "съесть" только зеленые фрукты
 // (демонстрация решения проблемы "в лоб")
 void DanceEmAllGreen(Iterator<Woman*> *it)
 {
     for(it->First(); !it->IsDone(); it->Next())
     {
         Woman *currentWoman = it->GetCurrent();
         if(currentWoman->GetColor() != skinColor::Black) continue;

         currentWoman->dance();
     }
 }
 /////////////////////////////////////////////////


// Декоратор итератора для выделения
class WomanColorDecorator : public IteratorDecorator<class Woman*>
{
private:
    skinColor TargetColor;

public:
    WomanColorDecorator(Iterator<Woman*>* it, skinColor color)
        : IteratorDecorator<Woman*>(it), TargetColor(color) {}

    void First()
    {
        this->It->First();
        while (!this->It->IsDone() && It->GetCurrent()->GetColor() != TargetColor)
        {
            this->It->Next();
        }
    }

    void Next()
    {
        do
        {
            this->It->Next();

        } while (!this->It->IsDone() && It->GetCurrent()->GetColor() != TargetColor);
    }
};

// Декоратор итератора для выделения
class WomanChildDecorator : public IteratorDecorator<class Woman*>
{
private:
    bool TargetGood;

public:
    WomanChildDecorator(Iterator<Woman*>* it, bool children) : IteratorDecorator<Woman*>(it), TargetGood(children) {}

    void First()
    {
        this->It->First();
        while (!this->It->IsDone() && this->It->GetCurrent()->haveChildren() != TargetGood)
        {
            this->It->Next();
        }
    }

    void Next()
    {
        do
        {
            this->It->Next();

        } while (!this->It->IsDone() && this->It->GetCurrent()->haveChildren() != TargetGood);
    }
};

int main() {
    srand(time(nullptr)); // Инициализация генератора

    /*cout << "Who is choose(1 - normal woman, 2 - old woman 3 - young woman)?" << endl;

    WomanType type = WomanType::Undefined;
    int ii;
    cin >> ii;
    type = static_cast<WomanType>(ii);*/
    int N = 5;

    //сложный способ создания обьектов

    /*Woman* newWoman = nullptr;
    if (type == WomanType::normalWoman) {
        newWoman = new normalWoman;
    }
    else if (type == WomanType::oldWoman) {
        newWoman = new oldWoman;
    }
    else if (type == WomanType::youngirl) {
        newWoman = new youngirl;
    }
    delete newWoman;*/

    /*Woman* newWoman2 = createWoman(type);

    cout << endl;
    size_t N = 0;
    cout << "input count woman: ";
    cin >> N;

    cout << endl;

    StackClass<normalWoman> normalStack;
    for (size_t i = 0; i < N; i++)
    {
        normalWoman newNormWoman;
        normalStack.Push(newNormWoman);
        delete newNormWoman;
    }
    delete newWoman2;*/

    StackClass<Woman*> WomanStack;
    for (size_t i = 0; i < N; i++)
    {
        int woman_num = rand() % 3 + 1; // Число от 1 до 3 (случайный woman)
        WomanType woman_type = static_cast<WomanType>(woman_num);
        Woman* newWoman = createWoman(woman_type);
        WomanStack.Push(newWoman);
    }

    cout << "size steck woman: " << WomanStack.Size() << endl;

    Iterator<Woman*>* it2 = WomanStack.GetIterator();

    cout << endl;

    Array<Woman*> WomanArray;
    for (size_t i = 0; i < N; i++)
    {
        int woman_num = rand() % 3 + 1;
        WomanType woman_type = static_cast<WomanType>(woman_num);
        Woman* newWoman = createWoman(woman_type);
        WomanArray.Add(newWoman);
    }

    wcout << "size array woman: " << WomanStack.Size() << endl;


    cout << "ONLY CLASS YOUNG GIRL HAS DARK SKIN COLOR" << endl;
    list<Woman*> WomanVector;
    for (size_t i = 0; i < N; i++)
    {
        int Woman_num = rand() % 3 + 1;
        WomanType Woman_type = static_cast<WomanType>(Woman_num);
        Woman* newWoman = createWoman(Woman_type);
        WomanVector.push_back(newWoman);
    }

    cout << "Stack class";

        cout << endl << "size stack: " << WomanStack.Size() << endl;
        Iterator<Woman*> *it7 = WomanStack.GetIterator();
        DanceEmAll(it7);
    cout << endl << "woman with black skin and children:" << endl;
        Iterator<Woman*>* childSkinIt =
        new WomanChildDecorator(new WomanColorDecorator(WomanStack.GetIterator(), skinColor::Black), true);
        DanceEmAll(childSkinIt);
        delete childSkinIt;

    // Обход всех женщин с детьми
    cout << "Array class" << endl;
    cout << endl << "walk woman onlle with children:" << endl;
    Iterator<Woman*>* childIt = new WomanChildDecorator(WomanArray.GetIterator(), true);
    DanceEmAll(childIt);
    delete childIt;

    // Обход всех темных женщин
    cout << endl << "woman with black skin:" << endl;
    Iterator<Woman*>* SkinIt = new WomanColorDecorator(WomanArray.GetIterator(), skinColor::Black);
    DanceEmAll(SkinIt);
    delete SkinIt;

    // Обход всех темных женщин с детьми
    cout << endl << "woman with black skin and children:" << endl;
    Iterator<Woman*>* haveChildIt =
        new WomanChildDecorator(new WomanColorDecorator(WomanArray.GetIterator(), skinColor::Black), true);
    DanceEmAll(haveChildIt);
    delete haveChildIt;

    // Демонстрация работы адаптера
    cout << endl << "Woman with black skin and children using adapted iterator (another container):" << endl;
    Iterator<Woman*>* adaptedIt = new ConstIteratorAdapter<std::list<Woman*>, Woman*>(&WomanVector);
    Iterator<Woman*>* adaptedBlackIt = new WomanChildDecorator(new WomanColorDecorator(adaptedIt, skinColor::Black), true);
    DanceEmAll(adaptedBlackIt);
    delete adaptedBlackIt;

    cout << "STL:" << endl;
    vector<Woman*> stlVector;
        for (int i = 0; i < 5; ++i) {
            int woman_num = rand() % 3 + 1;
            WomanType woman_type = static_cast<WomanType>(woman_num);
            Woman* newWoman = createWoman(woman_type);
            stlVector.push_back(newWoman);
    }

        Iterator<Woman*>* stlIt = new ConstIteratorAdapter<vector<Woman*>, Woman*>(&stlVector);
        DanceEmAll(stlIt);
        delete stlIt;
    return 0;
}
