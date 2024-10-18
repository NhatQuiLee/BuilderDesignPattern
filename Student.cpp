#include <iostream>
#include <string>
using namespace std;

class Student
{
    private:
        string name;
        float bandListen;
        float bandSpeak;
        float bandRead;
        float bandWrite;
    public:
        void SetName(string n)
        {
            name = n;
        }
        void SetListen(float l)
        {
            bandListen = l;
        }
        void SetSpeak(float s)
        {
            bandSpeak = s;
        }
        void SetRead(float r)
        {
            bandRead = r;
        }
        void SetWrite(float w)
        {
            bandWrite = w;
        }
        float Overall()
        {
            float average = (bandListen + bandSpeak + bandRead + bandWrite) / 4;
            return average;
        }
        void DisplayInformation()
        {
            cout << "Information: " << endl;
            cout << "Name: " << name << endl;
            cout << "Band Listening: " << bandListen << endl;
            cout << "Band Speaking: " << bandSpeak << endl;
            cout << "Band Reading: " << bandRead << endl;
            cout << "Band Writing: " << bandWrite << endl;
            cout << "Overall: " << Overall() << endl;
            cout << endl;
        }
};

class BuilderStudent
{
    public:
        virtual void BuilderSetName(string name) = 0;
        virtual void BuilderSetBandListening(float bandListen) = 0;
        virtual void BuilderSetBandSpeaking(float bandSpeak) = 0;
        virtual void BuilderSetBandReading(float bandRead) = 0;
        virtual void BuilderSetBandWriting(float bandWrite) = 0;
        virtual Student* GetResult() = 0;
};

class ConcreteBuilderStudent : public BuilderStudent
{
    private:
        Student* student;
    public:
        ConcreteBuilderStudent()
        {
            student = new Student();
        }
        virtual void BuilderSetName(string name) override
        {
            student->SetName(name);
        }
        virtual void BuilderSetBandListening(float bandListen) override
        {
            student->SetListen(bandListen);
        }
        virtual void BuilderSetBandSpeaking(float bandSpeak) override
        {
            student->SetSpeak(bandSpeak);
        }
        virtual void BuilderSetBandReading(float bandRead) override
        {
            student->SetRead(bandRead);
        }
        virtual void BuilderSetBandWriting(float bandWrite) override
        {
            student->SetWrite(bandWrite);
        }
        virtual Student* GetResult() override
        {
            return student;
        }
};

class DirectorBuilderStudent
{
    private:
        BuilderStudent* builderStudent;
    public:
        void SetStudent(BuilderStudent* student)
        {
            builderStudent = student;
        }
        void BuildStudentA(string name, float listen, float speak, float read, float write)
        {
            builderStudent->BuilderSetName(name);
            builderStudent->BuilderSetBandListening(listen);
            builderStudent->BuilderSetBandSpeaking(speak);
            builderStudent->BuilderSetBandReading(read);
            builderStudent->BuilderSetBandWriting(write);
        }
        void BuildStudentB(string name, float listen, float speak, float read, float write)
        {
            builderStudent->BuilderSetName(name);
            builderStudent->BuilderSetBandListening(listen);
            builderStudent->BuilderSetBandSpeaking(speak);
            builderStudent->BuilderSetBandReading(read);
            builderStudent->BuilderSetBandWriting(write);
        }
};

int main()
{
    DirectorBuilderStudent director;
    ConcreteBuilderStudent concreteBuilderStudent;
    director.SetStudent(&concreteBuilderStudent);

    director.BuildStudentA("Leo Messi", 7.0, 6.0, 7.0, 6.0);
    Student* studentA = concreteBuilderStudent.GetResult();
    studentA->DisplayInformation();

    director.BuildStudentB("Antonela", 8.0, 7.5, 8.0, 7.5);
    Student* studentB = concreteBuilderStudent.GetResult();
    studentB->DisplayInformation();

    delete studentA;
    delete studentB;

    return 0;
}
