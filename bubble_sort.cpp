#include <iostream>
#include <bits/stdc++.h>
#include "inc/SDL.h"
#include <cstdlib>
#undef main

using namespace std;
void draw(vector<int> &v, SDL_Renderer *renderer, int red, int blue)
{
    int index = 0;
    for (auto &it : v)
    {
        if (index == red)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (index == blue)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, index, 99, index, 99-it);
        index++;
    }
}

int main()
{
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_CreateWindowAndRenderer(100 * 8, 100 * 8, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 8, 8);
    vector<int> v(100);
    int i, j;
    for (auto &it : v)
        it = rand() % 100;
    for (i = 0; i < 100; i++)
    {
        for (j = i + 1; j < 100; j++)
        {
            if (v[i] > v[j])
                swap(v[i], v[j]);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            draw(v, renderer, i, j);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
    return 0;
}