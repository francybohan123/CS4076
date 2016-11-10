#include <iostream>
#include "admin.h"
using namespace std;
/*
 * Operator Overloading in practice
 */
Admin::Admin()
{

}

Admin::Admin(int x){
    newNumber = x;
}

Admin Admin::operator*(Admin number){
    Admin multipliedNumber; //create a new Admin object
    multipliedNumber.newNumber = newNumber + number.newNumber; //assign the object a number
    return(multipliedNumber); //return the object
}
