#include <iostream>  
#include <string>  
#include <vector>  
#include <ctime>  
using namespace std;  
class Shape {  
public:  
    virtual string draw() const = 0;  
    virtual ~Shape() {}  
};  
class Circle : public Shape {  
public:  
    string draw() const override {  
        return "Circle";  
    }  
};  
class Rectangle : public Shape {  
public:  
    string draw() const override {  
        return "Rectangle";  
    }  
};  
class Triangle : public Shape {  
public:  
    string draw() const override {  
        return "Triangle";  
    }  
};  
class Vector1 {  
private:  
    vector<Shape*> shapes;
public:  
    ~Vector1() {  
        for (Shape* shape : shapes) {  
            delete shape; 
        }  
    }  
    void insert(Shape* shape) {  
        shapes.push_back(shape);
    }  
    void remove(size_t index) {  
        if (index < shapes.size()) {  
            delete shapes[index]; 
            shapes.erase(shapes.begin() + index); 
        } else {  
            cout << "Try again!" << endl;  
        }  
    }  
    void display() const {  
        for (const Shape* shape : shapes) {  
            cout << shape->draw() << endl;  
        }  
    }  
    size_t size() const {  
        return shapes.size();  
    }  
};  
class Vector2 {  
private:  
    Shape** shapes;
    size_t capacity;  
    size_t count;  
    void resize() {  
        capacity *= 2;  
        Shape** newShapes = new Shape*[capacity];  
        for (size_t i = 0; i < count; ++i) {  
            newShapes[i] = shapes[i];  
        }  
        delete[] shapes; 
        shapes = newShapes;  
    }  
public:  
    Vector2() : count(0), capacity(2) {  
        shapes = new Shape*[capacity];  
    }  
    ~Vector2() {  
        for (size_t i = 0; i < count; ++i) {  
            delete shapes[i]; 
        }  
        delete[] shapes; 
    }  
    void insert(Shape* shape) {  
        if (count == capacity) {  
            resize(); 
        }  
        shapes[count++] = shape;  
    }  
    void remove(size_t index) {  
        if (index < count) {  
            delete shapes[index]; 
            for (size_t i = index; i < count - 1; ++i) {  
                shapes[i] = shapes[i + 1];  
            }  
            count--;  
        } else {  
            cout <<"Try again!"<< endl;  
        }  
    }  
    void display() const {  
        for (size_t i = 0; i < count; ++i) {  
            cout << shapes[i]->draw() << endl; 
        }  
    }  
    size_t size() const {  
        return count;  
    }  
};  
int main() {  
    Vector1 vector1;  
    vector1.insert(new Circle());  
    vector1.insert(new Rectangle());  
    vector1.insert(new Triangle());  
    cout << "Shapes in vector1:" <<endl;  
    vector1.display();  
    cout<< "Size: " << vector1.size() << endl;  
    cout<< "Enter the index you want to delete:"<<endl;  
    int index1;  
    cin>>index1;  
    vector1.remove(index1);  
    cout << "After removing:" <<endl;  
    vector1.display();  
    cout << "Size: " << vector1.size()<<endl;   
    clock_t start1 = clock();  
    for (int i = 0; i < 100; i++) {  
        vector1.insert(new Circle());  
    }  
    clock_t end1 = clock();  
    double time1 = double(end1 - start1) ;
    cout << "Time taken to add 100 shapes: " << time1 << " seconds" << endl;  
    vector1.display();  
    cout << "Size: " << vector1.size() << endl; 
    Vector2 vector2;  
    vector2.insert(new Circle());  
    vector2.insert(new Rectangle());  
    vector2.insert(new Triangle());  
    cout << "Shapes in vector2:" << endl;  
    vector2.display();  
    cout << "Size: " << vector2.size() << endl;  
    cout << "Enter the index you want to delete:" << endl;  
    int index2;  
    cin >> index2;  
    vector2.remove(index2);  
    cout << "After removing:" << endl;  
    vector2.display();  
    cout << "Size: " << vector2.size() << endl;  
    clock_t start2 = clock();  
    for (int i = 0; i < 100; i++) {  
        vector2.insert(new Circle());  
    }  
    clock_t end2 = clock();  
    double time2 = double(end2 - start2) ;
    cout << "Time taken to add 100 shapes: " << time2<<" seconds" <<endl;  
    vector2.display();  
    cout << "Size: " << vector2.size() << endl;  
    return 0;  
}