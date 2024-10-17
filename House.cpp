#include <iostream>
#include <string>

using namespace std;

//Product
class House
{
    private:
        string walls;
        string roof;
        string doors;
    public:
        void SetWalls(string w)
        {
            walls = w;
        }
        void SetRoof(string r)
        {
            roof = r;
        }
        void SetDoors(string d)
        {
            doors = d;
        }
        void showHouse()
        {
            cout << "House constructed including:" << endl;
            cout << "Walls: " << walls << endl;
            cout << "Roof: " << roof << endl;
            cout << "Doors: " << doors << endl;
        }
};

//Builder
class HouseBuilder
{
    public:
        virtual void Build_Walls() = 0;
        virtual void Build_Roof() = 0;
        virtual void Build_Doors() = 0;
        virtual House* GetHouse() = 0;
};

//HouseConcreteBuilder
class WoodenHouseConcreteBuilder : public HouseBuilder
{
    private:
        House* house;
    public:
        WoodenHouseConcreteBuilder()
        {
            house = new House();
        }
        void Build_Walls() override
        {
            house->SetWalls("Wooden Walls");
        }
        void Build_Roof() override
        {
            house->SetRoof("Wooden Roof");
        }
        void Build_Doors() override
        {
            house->SetDoors("Wooden Doors");
        }
        House* GetHouse() override
        {
            return house;
        }
};

class BrickHouseConcreteBuilder : public HouseBuilder
{
    private:
        House* house;
    public:
        BrickHouseConcreteBuilder()
        {
            house = new House();
        }
        void Build_Walls() override
        {
            house->SetWalls("Brick Walls");
        }
        void Build_Roof() override
        {
            house->SetRoof("Brick Roof");
        }
        void Build_Doors() override
        {
            house->SetDoors("Brick Doors");
        }
        House* GetHouse() override
        {
            return house;
        }
};

//Director
class Director
{
    private:
        HouseBuilder* houseBuilder;
    public:
        void SetBuilder(HouseBuilder* builder)
        {
            houseBuilder = builder;
        }
        void BuildHouse()
        {
            houseBuilder->Build_Walls();
            houseBuilder->Build_Roof();
            houseBuilder->Build_Doors();
        }
};

//Client
int main()
{
    Director director;

    WoodenHouseConcreteBuilder woodenHouseConcreteBuilder;
    director.SetBuilder(&woodenHouseConcreteBuilder);
    director.BuildHouse();
    House* woodenHouse = woodenHouseConcreteBuilder.GetHouse();
    woodenHouse->showHouse();
    cout << endl;

    BrickHouseConcreteBuilder brickHouseConcreteBuilder;
    director.SetBuilder(&brickHouseConcreteBuilder);
    director.BuildHouse();
    House* brickHouse = brickHouseConcreteBuilder.GetHouse();
    brickHouse->showHouse();

    delete woodenHouse;
    delete brickHouse;

    return 0;
}