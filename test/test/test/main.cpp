//
//  main.cpp
//  test
//
//  Created by James Schaedig on 11/8/18.
//  Copyright © 2018 James Schaedig. All rights reserved.
//

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void task1(string msg, int threadID)
{
    //thread racing
    cout << "thread " << threadID << " says: " << msg << endl;
    for(int i=0;i<10;i++)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << threadID << " Sleep: " << i << endl;
    }

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    thread t1(task1, "Hello", 1);
    
    thread t2(task1, "World", 2);
    
    t1.join();
    t2.join();
    
    return 0;
}

