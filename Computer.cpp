#include <iostream>
#include <string>
using namespace std;

class Computer
{
    private:
        string ram;
        string cpu;
        string storage;
    public:
        void SetRam(string r)
        {
            ram = r;
        }
        void SetCPU(string c)
        {
            cpu = c;
        }
        void SetStorage(string s)
        {
            storage = s;
        }
        void displayInformation()
        {
            cout << "Display information:" << endl;
            cout << "RAM: " << ram << endl;
            cout << "CPU: " << cpu << endl;
            cout << "Storage: " << storage << endl;
            cout << endl;
        }
};

class BuilderComputer
{
    public:
        virtual void BuildRam() = 0;
        virtual void BuildCPU() = 0;
        virtual void BuildStorage() = 0;
        virtual Computer* GetComputer() = 0;
};

class DELLConcreteBuilderComputer : public BuilderComputer
{
    private:
        Computer* computer;
    public:
        DELLConcreteBuilderComputer()
        {
            computer = new Computer();
        }
        void BuildRam()
        {
            computer->SetRam("DELL RAM");
        }
        void BuildCPU()
        {
            computer->SetCPU("DELL CPU");
        }
        void BuildStorage()
        {
            computer->SetStorage("DELL Storage");
        }
        Computer* GetComputer()
        {
            return computer;
        }
};

class HPConcreteBuilderComputer : public BuilderComputer
{
    private:
        Computer* computer;
    public:
        HPConcreteBuilderComputer()
        {
            computer = new Computer();
        }
        void BuildRam()
        {
            computer->SetRam("HP RAM");
        }
        void BuildCPU()
        {
            computer->SetCPU("HP CPU");
        }
        void BuildStorage()
        {
            computer->SetStorage("HP Storage");
        }
        Computer* GetComputer()
        {
            return computer;
        }
};

class DirectorComputer
{
    private:
        BuilderComputer* builderComputer;
    public:
        void SetBuilder(BuilderComputer* builder)
        {
            builderComputer = builder;
        }
        void BuildComputer()
        {
            builderComputer->BuildRam();
            builderComputer->BuildCPU();
            builderComputer->BuildStorage();
        }
};

int main()
{
    DirectorComputer director;

    DELLConcreteBuilderComputer DELLConcreteBuilderComputer;
    director.SetBuilder(&DELLConcreteBuilderComputer);
    director.BuildComputer();
    Computer* DELLComputer = DELLConcreteBuilderComputer.GetComputer();
    DELLComputer->displayInformation();

    HPConcreteBuilderComputer HPConcreteBuilderComputer;
    director.SetBuilder(&HPConcreteBuilderComputer);
    director.BuildComputer();
    Computer* HPComputer = HPConcreteBuilderComputer.GetComputer();
    HPComputer->displayInformation();
    return 0;
}