#include <iostream>

using namespace std;

/* NOTE : protected and private virtual functions are not allowed */ 
/* because this voilets the rule of dynamic binding */
class Car
{
	public:
		Car() {}
		Car(Car& obj)
		{
			/* called for SportsCar obj */
			obj.GetCarType();
			
			/* local class function called */
			GetCarType();
			cout << " Copy constructor called" << endl;
		}
		virtual ~Car() {}
		virtual void GetGear() { cout << " Car gear returned " << endl; }
		virtual void GetCarType() { cout <<"This is car " << endl; }
};

class SportsCar : public Car
{
	public:
		SportsCar() {}
		~SportsCar () {}
		private:  // this does not make any sense. 
		void GetCarType()
		{
			cout << " Car type is sports car" << endl;
		}
};

class Limo : public Car
{
	public:
		Limo() {}
		~Limo () {}
		private:
		void GetCarType() 
		{
			cout << " Car type is Limo car" << endl;
		}
};

int main()
{
	SportsCar sportsCarObj;
	Car * carObj = &sportsCarObj;
	carObj->GetCarType();
	carObj->GetGear();
	
	Limo limoCarObj;
	carObj = &limoCarObj;
	carObj->GetCarType();
	
	/* copy constructor */
	Car newCar = sportsCarObj;
}
