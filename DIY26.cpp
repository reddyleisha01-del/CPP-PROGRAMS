#include <iostream>
#include <exception>
using namespace std;

struct MathError : exception {
    const char* what() const noexcept override { return "math error"; }
};
struct DivideByZero : MathError {
    const char* what() const noexcept override { return "divide by zero"; }
};

int main() {
    // WRONG ORDER: base first -> derived handler is hidden (g++ -Wall warns about it)
    try { throw DivideByZero(); }
    catch (const MathError &e)    { cout << "Wrong order -> caught by MathError: " << e.what() << endl; }
    catch (const DivideByZero &e) { cout << "DivideByZero handler: " << e.what() << endl; }

    // CORRECT ORDER: derived first
    try { throw DivideByZero(); }
    catch (const DivideByZero &e) { cout << "Correct order -> caught by DivideByZero: " << e.what() << endl; }
    catch (const MathError &e)    { cout << "MathError handler: " << e.what() << endl; }
    return 0;
}
