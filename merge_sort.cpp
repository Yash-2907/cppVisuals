#include<bits/stdc++.h>
#include "inc/SDL.h"
using namespace std;
#undef main

void draw(vector<int> &v, SDL_Renderer *renderer, int left_inner, int right_inner,int left_outer,int right_outer)
{
    int index = 0;
    for (auto &it : v)
    {
        if (index == left_inner)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (index == right_inner)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else if(index>=left_outer && index<=right_outer)
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, index, 99-it, index, 99);
        index++;
    }
}

void merge(vector<int> &v, int start, int end, int mid, SDL_Renderer *renderer)
{
    int size1 = mid - start + 1, size2 = end - mid + 1,ptr1=start,ptr2=mid+1,ptr3=0;
    vector<int> temp(end-start+1);
    while(ptr1<=mid && ptr2<=end)
    {
        if(v[ptr1]<v[ptr2])
        {
            temp[ptr3]=v[ptr1];
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            draw(v, renderer, ptr1, ptr2, start, end);
            SDL_RenderPresent(renderer);
            SDL_Delay(60);
            ptr1++;
        }
        else{
            temp[ptr3] = v[ptr2];
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            draw(v, renderer, ptr1, ptr2, start, end);
            SDL_RenderPresent(renderer);
            SDL_Delay(60);
            ptr2++;
        }
        ptr3++;
    }
    while(ptr1<=mid)
    {
        temp[ptr3] = v[ptr1];
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        draw(v, renderer, ptr1, ptr2, start, end);
        SDL_RenderPresent(renderer);
        SDL_Delay(60);
        ptr1++;
        ptr3++;
    }
    while(ptr2<=end)
    {
        temp[ptr3] = v[ptr2];
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        draw(v, renderer, ptr1, ptr2, start, end);
        SDL_RenderPresent(renderer);
        SDL_Delay(60);
        ptr2++;
        ptr3++;
    }
    for(int i=0;i<end-start+1;i++)
    {
        v[start+i]=temp[i];
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        draw(v, renderer, start+i, -1, start, end);
        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }
}

void divide(vector<int>& v,int start,int end,SDL_Renderer *renderer)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        divide(v,start,mid,renderer);
        divide(v,mid+1,end,renderer);
        merge(v,start,end,mid,renderer);
    }
}

int main()
{
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_CreateWindowAndRenderer(100 * 8, 100 * 8, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 8, 8);
    vector<int> v(100);
    int size=v.size();
    for (auto &it : v)
        it = rand() % 100;
    divide(v,0,size-1,renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    draw(v, renderer, -1, -1, 0, size);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
}