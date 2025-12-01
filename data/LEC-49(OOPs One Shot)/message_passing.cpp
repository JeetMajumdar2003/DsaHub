#include <iostream>
using namespace std;

// Define a Car class with a method to display its speed
class Car {
public:
    void displaySpeed(int speed) {
        cout << "The car is moving at " << speed << " km/h." << endl;
    }
};

int main() {
    // Create a Car object named myCar
    Car myCar;

    // Send a message to myCar to execute the displaySpeed method
    int currentSpeed = 100;
    myCar.displaySpeed(currentSpeed);

    return 0;
}

/** Message Passing in Object-Oriented Programming (OOP) Explained:
 * Message passing is a fundamental concept in Object-Oriented Programming (OOP) that allows objects to communicate with each other. Here's a breakdown of the concept:

 * What is Message Passing?
 * Message passing involves sending a request from one object to another to invoke a method and perform a specific action. This is akin to how we send messages in real life to request information or action.

 * Key Components:
 * 1. Sender: The object that sends the message.
 * 2. Receiver: The object that receives the message and performs the requested action.
 * 3. Message: The request itself, which includes the method name and any necessary parameters.

 * How It Works:
 * When an object sends a message to another object, it essentially calls a method on that object. The receiver then processes the message and executes the corresponding method.

 * Example Explained:
 * Let's revisit your example to illustrate message passing:

 * Breakdown:
 * 1. Sender: The `main` function acts as the sender.
 * 2. Receiver: The `myCar` object of the `Car` class is the receiver.
 * 3. Message: The message is the call to `myCar.displaySpeed(currentSpeed)`.

 * In this example, the `main` function sends a message to the `myCar` object to execute the `displaySpeed` method with the parameter `currentSpeed`. The `myCar` object receives this message and performs the action of displaying the car's speed.

 * Benefits of Message Passing:
 * - Encapsulation: Objects hide their internal state and only expose methods to interact with them.
 * - Modularity: Objects can be developed and tested independently.
 * - Flexibility: Objects can interact in a loosely coupled manner, making the system more adaptable to changes.

 * Message passing is a powerful way to design systems where objects interact seamlessly while maintaining their own responsibilities and behaviors.

 * Does this help clarify the concept? If you have more questions or need further details, feel free to ask!

 * Source:
 * - Conversation with Copilot, 8/1/2024
 * - (1) Message Passing in Object Oriented Programming (OOP) - EnjoyAlgorithms. https://www.enjoyalgorithms.com/blog/message-passing-oops/
 * - (2) An Overview of Message Passing in Object-Oriented Programming. https://panonit.com/blog/overview-message-passing-object-oriented-programming
 * - (3) Message Passing :: CC 410 Textbook - Kansas State University. https://textbooks.cs.ksu.edu/cc410/i-oop/02-object-oriented-programming/11-message-passing/
 * - (4) Introduction of Object Oriented Programming - GeeksforGeeks. https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/
 * - (5) models - What is message passing in OOP? - Stack Overflow. https://stackoverflow.com/questions/34765555/what-is-message-passing-in-oop/
 */
