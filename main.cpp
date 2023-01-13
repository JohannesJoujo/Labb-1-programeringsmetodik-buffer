#include "/Users/JohannesJoujo/CLionProjects/untitled1/cmake-build-debug/int_sorted.h"
#include <chrono>

void f(int_buffer& buf);
void ff(int_buffer& buff);
void fff(int_sorted buf);

int main() {
    srand((unsigned)time(NULL));

/*
    std::cout<<"Random didgits for vem:\n";
    int_buffer vem(10);
    f(vem);
    std::cout<<"\n-----------------------------------\n";
    std::cout<<"Random didgits for vet:\n";
    int_buffer vet(10);
    ff(vet);
    std::cout<<"\n-----------------------------------\n";

*/
/*
    int_sorted fbuf(nullptr,0);
    fff(fbuf);
    fbuf.test_if();
*/

/*
    int_buffer nbuf(40000);
    for(auto &e: nbuf){
        e=rand()%39999+1;
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    std::sort(nbuf.begin(),nbuf.end());
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto mergetime1 = std::chrono::duration<double>(stop1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    int_sorted buffer(nbuf.begin(),nbuf.size());
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto mergetime2 = std::chrono::duration<double>(stop2 - start2);


    for (auto &e:buffer) {
        std::cout<<e<<" ";
    }
    std::cout << "\n\nTime taken by std::sort(): "
              << mergetime1.count() << "seconds" << std::endl;

    std::cout << "\nTime taken by merge: "
              << mergetime2.count() << "seconds" << std::endl;

    buffer.test_if();
    */

    return 0;
}


void f(int_buffer &buf)
{
    for (int *i = buf.begin(); i != buf.end(); i++){
        *i = rand() % 10 + 1;
    }
    for (const int *i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << ", ";
    }
}

void ff(int_buffer& buff){

    for (auto &e: buff) {
        e=rand() % 10 + 1;
    }
    for (auto e: buff) {
        std::cout << e << ", ";
    }
}

void fff(int_sorted buf){
    for(int i=0; i<500;i++){
        buf.insert(rand() % 499 + 1);
    }

    for (auto e: buf) {
        std::cout << e << ", ";
    }
    std::cout<<std::endl;
}


