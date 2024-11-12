#include <iostream>
#include "Page.h"

int main()
{
    Page page;
    page.init();

    page.addLineToPosts("hello wold");
    page.addLineToPosts("whatsup?");

    std::cout << page.getPosts();

    return 0;
}