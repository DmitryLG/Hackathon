#include <stdio.h>
#include <cmath>
#include <iostream>

class ReversedNum {

    private:
        int number;
        
        ReversedNum* delnull() {	//delete extra nulls
            while(!number%10)
                number/=10;
                return this;
            }

        int length() {				//returns length of the number
            return int(ceil(log10(number)));
            }

    public:

        int shownum() {				//returns the number
            return number;
            }

        ReversedNum(int a): number(a) {delnull();};		//initializing constructor

        ReversedNum operator + (ReversedNum& secoper) {		//overloaded new rules plus operation
            bool overload = false;
            int temp = 0, result = 0, num2, places[]={this->length(), secoper.length()};
			num2 = secoper.shownum();
            while((places[0]>0)||(places[1]>0)||overload){
                temp = int(double(number)/pow(10, --places[0]))%10 + int(double(num2)/pow(10, --places[1]))%10;		//highest digits sum, second highest digits sum and so on
                if (overload) temp++;
                if (temp/10) overload = true;
                    else overload = false;
                result = result*10 + temp%10;	//creating new number
                temp = 0;
                }
            return ReversedNum(result);
            };
    };

int main(){
    int times;
    std::cin >> times;
        while(times--){
            int foper, soper;
            ReversedNum* a;
            ReversedNum* b;
            std::cin >> foper >> soper;		//entering operands 
            a = new ReversedNum(foper);
            b = new ReversedNum(soper);
            std::cout << (*a+*b).shownum() << '\n';		//overloaded plus operating and outputting value
            delete a, b;
        }
    return 0;
    }
            
            
            
        
