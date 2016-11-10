#ifndef ADMIN_H
#define ADMIN_H


class Admin
{
public:
    int newNumber;
    Admin(); //Admin Object
    Admin(int);
    Admin operator*(Admin);//Operator Overloading
};

#endif // ADMIN_H
