#include "Neighbourhood.hpp"

Neighbourhood::Neighbourhood(unsigned size, unsigned step) :
    size_(size), step_(step)
{}
    
void Neighbourhood::start() {
    p_ = std::make_pair(0, step_);
}

bool Neighbourhood::isValid() {
    return p_.first + step_ < size_;
}

void Neighbourhood::next() {
    p_.first++;
    p_.second = p_.first + step_;
}

Neighbourhood::operator Point() const {
    return p_;
}

unsigned Neighbourhood::first() {
    return p_.first;
}

unsigned Neighbourhood::second() {
    return p_.second;
}

std::ostream& operator<<(std::ostream& ostr, const Point& p) {
    ostr << "(" << p.first << "," << p.second << ")";

    return ostr;
}