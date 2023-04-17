#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX_FRAME_DELAY     20
#define MIN_FRAME_DELAY      1

typedef enum Tela { PressContinue = 0, Instrucoes, Cenario, Personagem, GAMEPLAY, ENDING } Tela;
typedef enum Adversario { Ad1 = 0, Ad2, Ad3} Adversario;
typedef enum Poke { P1 = 0, P2, P3} Poke;

typedef struct no
{
    int danoAtaqueAr;
    int velocidadeAtaqueAr;
    int danoAtaqueFogo;
    int velocidadeAtaqueFogo;
    int danoAtaqueGrama;
    int velocidadeAtaqueGrama;
    int danoAtaqueAgua;
    int velocidadeAtaqueAgua;
    int codBicho;
    struct no *proximo;
}NoPokemonsJogador;


typedef struct noAd
{
    int danoAtaqueAr;
    int velocidadeAtaqueAr;
    int danoAtaqueFogo;
    int velocidadeAtaqueFogo;
    int danoAtaqueGrama;
    int velocidadeAtaqueGrama;
    int danoAtaqueAgua;
    int velocidadeAtaqueAgua;
    int codBicho;
    struct noAd *proximo;
}NoPokemonsAdversario;


void enfileirarJogador(NoPokemonsJogador **fila)
{
    int cods[3];
    for (int j = 0; j < 3; j++)
    {
       cods[j] = GetRandomValue(0, 2);
       for(int i = 0; i < j; i++)
       {
          if(cods[j] == cods[i]){
            j--;
            break;
          }
       }
    }

     for (int j = 0; j < 3; j++) {
        int i = rand() % 3;
        int temp = cods[j];
        cods[j] = cods[i];
        cods[i] = temp;
    }

    for(int i = 0; i < 3; i++)
    {
        NoPokemonsJogador *aux, *novo = malloc(sizeof(NoPokemonsJogador));

        int danoAtaqueArRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueArRandom = 60;
        int danoAtaqueFogoRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueFogoRandom = 40;
        int danoAtaqueGramaRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueGramaRandom = 30;
        int danoAtaqueAguaRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueAguaRandom = 50;
        int codBichoRandom = cods[i];

        if(novo)
        {
            novo->danoAtaqueAr = danoAtaqueArRandom;
            novo->velocidadeAtaqueAr = 60;
            novo->danoAtaqueFogo = danoAtaqueFogoRandom;
            novo->velocidadeAtaqueFogo = 40;
            novo->danoAtaqueGrama = danoAtaqueGramaRandom;
            novo->velocidadeAtaqueGrama = 30;
            novo->danoAtaqueAgua = danoAtaqueAguaRandom;
            novo->velocidadeAtaqueAgua = 50;
            novo->codBicho = codBichoRandom;
            novo->proximo = NULL;

            if(*fila == NULL)
                *fila = novo;

            else
            {
                aux = *fila;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
}

void enfileirarAdversario(NoPokemonsAdversario **fila)
{
    int cods[3];
    for (int j = 0; j < 3; j++)
    {
       cods[j] = GetRandomValue(0, 2);
       for(int i = 0; i < j; i++)
       {
          if(cods[j] == cods[i]){
            j--;
            break;
          }
       }
    }

     for (int j = 0; j < 3; j++) {
        int i = rand() % 3;
        int temp = cods[j];
        cods[j] = cods[i];
        cods[i] = temp;
    }

    for(int i = 0; i < 3; i++)
    {
        NoPokemonsAdversario *aux, *novo = malloc(sizeof(NoPokemonsAdversario));

        int danoAtaqueArRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueArRandom = 60;
        int danoAtaqueFogoRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueFogoRandom = 40;
        int danoAtaqueGramaRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueGramaRandom = 30;
        int danoAtaqueAguaRandom = GetRandomValue(2, 10);
        int velocidadeAtaqueAguaRandom = 50;
        int codBichoRandom = cods[i];

        if(novo)
        {
            novo->danoAtaqueAr = danoAtaqueArRandom;
            novo->velocidadeAtaqueAr = 60;
            novo->danoAtaqueFogo = danoAtaqueFogoRandom;
            novo->velocidadeAtaqueFogo = 40;
            novo->danoAtaqueGrama = danoAtaqueGramaRandom;
            novo->velocidadeAtaqueGrama = 30;
            novo->danoAtaqueAgua = danoAtaqueAguaRandom;
            novo->velocidadeAtaqueAgua = 50;
            novo->codBicho = codBichoRandom;
            novo->proximo = NULL;

            if(*fila == NULL)
                *fila = novo;
        else
        {
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        }
    }
}

int countRemovidoJogador = 0;
NoPokemonsJogador* retiraPokemonJogador(NoPokemonsJogador **fila, int posicao)
{

    NoPokemonsJogador *remover = NULL;

    for(int i = 0; i <= posicao; i++)
    {
        if(*fila)
        {
            remover = *fila;
            if(countRemovidoJogador < posicao)
            {
                *fila = remover -> proximo;
                countRemovidoJogador++;
            }

        }
    }
    return remover;
}


int countRemovidoAdversario = 0;
NoPokemonsAdversario* retiraPokemonAdversario(NoPokemonsAdversario **filaAd, int posicao)
{
    NoPokemonsAdversario *remover = NULL;

 for(int i = 0; i <= posicao; i++)
    {
        if(*filaAd)
        {
            remover = *filaAd;
             if(countRemovidoAdversario < posicao)
            {
                *filaAd = remover -> proximo;
                countRemovidoAdversario++;
            }
        }
    }

    return remover;
}

int main(void)
{
    InitAudioDevice();

    const int screenWidth = 790;
    const int screenHeight = 470;
    InitWindow(screenWidth, screenHeight, "Pokemon Clash!");

    //SONS
    Sound musicaMenu = LoadSound("./assets/menu-sv.ogg");
    Sound vitoria = LoadSound("./assets/victory.ogg");
    Sound musicaBatalha1 = LoadSound("./assets/battle-cw-legendsarceus.mp3");
    Sound musicaBatalha2 = LoadSound("./assets/battle-t-sm.mp3");
    Sound musicaBatalha3 = LoadSound("./assets/battle-am-usum.mp3");
    Sound musicaBatalha4 = LoadSound("./assets/battle-uma-bdsp.mp3");
    //SONS

    //VARIÁVEIS
    int menuFrames = 0;
    int FramesPersonagem = 0;

    Tela currentScreen = PressContinue;
    Adversario currentAdversario = Ad1;
    Poke currentPoke = P1;

    NoPokemonsJogador* r, *fila = NULL;
    NoPokemonsAdversario* rAd, *filaAd = NULL;
    Color backgroundColor = RAYWHITE;
    //VARIÁVEIS

    //FONT
    Font fonte = LoadFont("./assets/pokemon/fonts/pokemon-ds-font.ttf");
    //FONT

   //MENU
   Texture2D bgMenu = LoadTexture("./assets/test-bg.png");
   Image menuGif = LoadImageAnim("./assets/menubg.gif", &menuFrames);
   Texture2D texGifao = LoadTextureFromImage(menuGif);
   //MENU

   //INSTRUÇÕES
   Texture2D bgMenuInst = LoadTexture("./assets/bgMenuInst.png");
   Image menuGifBlur = LoadImageAnim("./assets/blur-menubg.gif", &menuFrames);
   Texture2D texGifaoBlur = LoadTextureFromImage(menuGifBlur);
   //INSTRUÇÕES

   //BOTÃO
   Texture2D botaoPlay = LoadTexture("./assets/button-pink-play.png");
   Texture2D botaoInst = LoadTexture("./assets/button-hover-instr.png");
   Texture2D botaoMenu = LoadTexture("./assets/button-pink-menu.png");

   Rectangle retPlay = { 150, 270, botaoPlay.width, botaoPlay.height };
   Rectangle retInst = { 420, 270, botaoInst.width, botaoInst.height };
   Rectangle retMenuInst = { 287, 385, botaoPlay.width, botaoPlay.height };
   //BOTÃO

   //CENARIOS
   Texture2D cenarioSelect = LoadTexture("./assets/cenarioSelect.png");

   Image cenario1 = LoadImageAnim("./assets/forest2.gif", &menuFrames);
   Image cenario2 = LoadImageAnim("./assets/water2.gif", &menuFrames);
   Image cenario3 = LoadImageAnim("./assets/water.gif", &menuFrames);
   Image cenario4 = LoadImageAnim("./assets/cave.gif", &menuFrames);

   Texture2D cen1tex = LoadTextureFromImage(cenario1);
   Texture2D cen2tex = LoadTextureFromImage(cenario2);
   Texture2D cen3tex = LoadTextureFromImage(cenario3);
   Texture2D cen4tex = LoadTextureFromImage(cenario4);

   Rectangle recCenario1 = { 0, 0, 330, 220 };
   Rectangle recCenario2 = { 400, 0, 330, 220 };
   Rectangle recCenario3 = { 0, 240, 330, 220 };
   Rectangle recCenario4 = { 400, 240, 330, 220 };
   //CENARIOS

   //POKEMONS
   Texture2D pokemonJog1 = LoadTexture("./assets/pokemonJogador1.png");
   Texture2D pokemonJog2 = LoadTexture("./assets/pokemonJogador2.png");
   Texture2D pokemonJog3 = LoadTexture("./assets/pokemonJogador3.png");

   Texture2D pokemonAd1 = LoadTexture("./assets/pokemonAd1.png");
   Texture2D pokemonAd2 = LoadTexture("./assets/pokemonAd2.png");
   Texture2D pokemonAd3 = LoadTexture("./assets/pokemonAd3.gif");

   //POSIÇÃO DOS POKEMONS
   Vector2 posicaoPokemon = { 150, 200 };
   Vector2 posicaoPokemonAd = { 420, 100 };
   //POKEMONS

   //ATAQUES
   Texture2D atkFire = LoadTexture("./assets/attack-fire.png");
   Texture2D atkWater = LoadTexture("./assets/attack-water.png");
   Texture2D atkGrass = LoadTexture("./assets/attack-grass.png");
   Texture2D atkAir = LoadTexture("./assets/attack-air.png");

   Rectangle retanguloFogo = { 10, 405, atkFire.width, atkFire.height };
   Rectangle retanguloAgua = { 203,405, atkWater.width, atkWater.height };
   Rectangle retanguloGrama = { 397,405, atkGrass.width, atkGrass.height };
   Rectangle retanguloAr = { 590,405, atkAir.width, atkAir.height };


   //SPRITES ATAQUES JOGADOR 1
   Image ataqueFogoI = LoadImage("./assets/fireball.png");
   ImageResize(&ataqueFogoI,50,30);
   Texture2D ataqueFogo = LoadTextureFromImage(ataqueFogoI);

   Image ataqueAguaI = LoadImage("./assets/waterball.png");
   ImageResize(&ataqueAguaI,50,30);
   Texture2D ataqueAgua = LoadTextureFromImage(ataqueAguaI);

   Image ataqueTerraI = LoadImage("./assets/grassball.png");
   ImageResize(&ataqueTerraI,50,30);
   Texture2D ataqueTerra = LoadTextureFromImage(ataqueTerraI);

   Image ataqueArI = LoadImage("./assets/airball.png");
   ImageResize(&ataqueArI,50,30);
   Texture2D ataqueAr = LoadTextureFromImage(ataqueArI);

   //SPRITES ATAQUES JOGADOR 2
   Image ataqueFogoAdI = LoadImage("./assets/fireballAd.png");
   ImageResize(&ataqueFogoAdI,50,30);
   Texture2D ataqueFogoAd = LoadTextureFromImage(ataqueFogoAdI);

   Image ataqueAguaAdI = LoadImage("./assets/waterballAd.png");
   ImageResize(&ataqueAguaAdI,50,30);
   Texture2D ataqueAguaAd = LoadTextureFromImage(ataqueAguaAdI);

   Image ataqueTerraAdI = LoadImage("./assets/grassballAd.png");
   ImageResize(&ataqueTerraAdI,50,30);
   Texture2D ataqueTerraAd = LoadTextureFromImage(ataqueTerraAdI);

   Image ataqueArAdI = LoadImage("./assets/airballAd.png");
   ImageResize(&ataqueArAdI,50,30);
   Texture2D ataqueArAd = LoadTextureFromImage(ataqueArAdI);

   //POSIÇÃO ATAQUES
   Vector2 vectorAtaque = {(float)200, (float)280};
   Vector2 vectorAtaqueAd = {(float)500, (float)200};
   //ATAQUES

   //TOPO
   Texture2D healthBarP1 = LoadTexture("./assets/healthbarp1.png");
   Texture2D healthBarP2 = LoadTexture("./assets/healthbarp2.png");
   Texture2D timerP1 = LoadTexture("./assets/timerp1.png");
   Texture2D timerP2 = LoadTexture("./assets/timerp2.png");
    //TOPO

   //PERSONAGENS
   Texture2D meninaPrincipal = LoadTexture("./assets/female-right.png");
   Texture2D meninaSecundario = LoadTexture("./assets/female-left.png");
   Texture2D meninoPrincipal = LoadTexture("./assets/male-right.png");
   Texture2D meninoSecundario = LoadTexture("./assets/male-left.png");

   Rectangle retanguloMenina = { 330, 0, 330, 250 };
   Rectangle retanguloMenino = { 0, 0, 330, 250 };

   Texture2D charSelect = LoadTexture("./assets/charSelect.png");
   //PERSONAGENS


  //ENCERRAMENTO
   Texture2D endingP1 = LoadTexture("./assets/ending1.png");
   Texture2D endingP2 = LoadTexture("./assets/ending2.png");


   //VARIÁVEIS DE CONTROLE
   bool meninaBool = false,
   meninoBool = false,
   cenario1bool = false,
   cenario1boo2 = false,
   cenario1boo3 = false,
   cenario1boo4 = false,
   jogador1jogou = true,
   jogador2jogou = false,
   tomouDano = false,
   atacouJog = false,
   atacouAd = false;

   int vitoriasJogador = 0,
   vitoriasAdversario = 0,
   vidas = 3,
   vidaAdversario = 3,
   suporteDano = 100,
   suporteDanoAd = 100,
   countAdversario = 0,
   countPokemon = 0,
   codAtaque = 0,
   codAtaqueAd = 0,
   danoJog = 0,
   danoAd = 0;

   unsigned int nextFrameDataOffsetMenu = 0;
   unsigned int nextFrameDataOffsetMenuBlur = 0;
   unsigned int nextFrameDataOffsetMenuCen1 = 0;
   unsigned int nextFrameDataOffsetMenuCen2 = 0;
   unsigned int nextFrameDataOffsetMenuCen3 = 0;
   unsigned int nextFrameDataOffsetMenuCen4 = 0;
   unsigned int nextFrameDataOffsetPoke1 = 0;
   unsigned int nextFrameDataOffsetPoke2 = 0;
   unsigned int nextFrameDataOffsetPoke3 = 0;

   int currentAnimFrame = 0,
   frameDelay = 8,
   frameCounter = 0;

   const float displayTime = 2.5f,
   displayAttack = 1.0f,
   displayAttackAd = 1.0f;

   float elapsedTime = 0.0f,
   elapsedTimeAttack = 0.0f,
   elapsedTimeAttackAd = 0.0f;
   //VARIÁVEIS DE CONTROLE


   SetTargetFPS(60);

   //Deve dar o play na musica antes do loop
   PlaySound(musicaMenu);

   //como a musica de batalha deve tocar apenas na arena, damos o play e depois um pause para não continuar, na tela de batalha nós damos Resume.
   PlaySound(musicaBatalha1);
   PauseSound(musicaBatalha1);

   PlaySound(musicaBatalha2);
   PauseSound(musicaBatalha2);

   PlaySound(musicaBatalha3);
   PauseSound(musicaBatalha3);

   PlaySound(musicaBatalha4);
   PauseSound(musicaBatalha4);

   PlaySound(vitoria);
   PauseSound(vitoria);

   while (!WindowShouldClose())
    {

        frameCounter++;
        //frameCounterPersonagem++;

        if (frameCounter >= frameDelay)
        {
            currentAnimFrame++;
            if (currentAnimFrame >= menuFrames) currentAnimFrame = 0;

            nextFrameDataOffsetMenu = menuGif.width*menuGif.height*4*currentAnimFrame;
            nextFrameDataOffsetMenuBlur = menuGifBlur.width*menuGifBlur.height*4*currentAnimFrame;
            nextFrameDataOffsetMenuCen1 = cenario1.width*cenario1.height*4*currentAnimFrame;
            nextFrameDataOffsetMenuCen2 = cenario2.width*cenario2.height*4*currentAnimFrame;
            nextFrameDataOffsetMenuCen3 = cenario3.width*cenario3.height*4*currentAnimFrame;
            nextFrameDataOffsetMenuCen4 = cenario4.width*cenario4.height*4*currentAnimFrame;


            UpdateTexture(texGifao, ((unsigned char *)menuGif.data) + nextFrameDataOffsetMenu);
            UpdateTexture(texGifaoBlur, ((unsigned char *)menuGifBlur.data) + nextFrameDataOffsetMenuBlur);
            UpdateTexture(cen1tex, ((unsigned char *)cenario1.data) + nextFrameDataOffsetMenuCen1);
            UpdateTexture(cen2tex, ((unsigned char *)cenario2.data) + nextFrameDataOffsetMenuCen2);
            UpdateTexture(cen3tex, ((unsigned char *)cenario3.data) + nextFrameDataOffsetMenuCen3);
            UpdateTexture(cen4tex, ((unsigned char *)cenario4.data) + nextFrameDataOffsetMenuCen4);

            frameCounter = 0;
        }

        //verificações pra passar de tela
        switch(currentScreen)
        {
            case PressContinue:
            {
               if (CheckCollisionPointRec(GetMousePosition(), retPlay) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = Cenario;
                }if (CheckCollisionPointRec(GetMousePosition(), retInst) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = Instrucoes;
                }
            } break;
            case Instrucoes:
            {
                if (CheckCollisionPointRec(GetMousePosition(), retMenuInst) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = PressContinue;
                }
            } break;
            case Cenario:
            {
                if (CheckCollisionPointRec(GetMousePosition(), recCenario1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = Personagem;
                    cenario1bool = true;
                } else if (CheckCollisionPointRec(GetMousePosition(), recCenario2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = Personagem;
                    cenario1boo2 = true;
                }else if (CheckCollisionPointRec(GetMousePosition(), recCenario3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = Personagem;
                    cenario1boo3 = true;
                }else if (CheckCollisionPointRec(GetMousePosition(), recCenario4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = Personagem;
                    cenario1boo4 = true;
                }
            } break;
            case Personagem:
            {
                if (CheckCollisionPointRec(GetMousePosition(), retanguloMenina) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    enfileirarJogador(&fila);
                    enfileirarAdversario(&filaAd);
                    currentScreen = GAMEPLAY;
                    meninaBool = true;
                } else if (CheckCollisionPointRec(GetMousePosition(), retanguloMenino) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    enfileirarJogador(&fila);
                    enfileirarAdversario(&filaAd);
                    currentScreen = GAMEPLAY;
                    meninoBool = true;
                }
            } break;

            case GAMEPLAY:
            {

                        if(countAdversario == 0)
                            currentAdversario = Ad1;
                        else if (countAdversario == 1)
                            currentAdversario = Ad2;
                        else if(countAdversario == 2)
                            currentAdversario = Ad3;

                        if(countPokemon == 0)
                            currentPoke = P1;
                        else if (countPokemon == 1)
                            currentPoke = P2;
                        else if(countPokemon == 2)
                            currentPoke = P3;


                        if(vidas > 0 && vidaAdversario > 0)
                        {
                            if(suporteDanoAd <= 0)
                            {
                                countAdversario++;
                                vitoriasJogador++;
                                suporteDano = 100;
                                suporteDanoAd = 100;
                                vidaAdversario--;

                            } else if(suporteDano <= 0)
                            {
                                countPokemon++;
                                vidas--;
                                suporteDano = 100;
                                suporteDanoAd = 100;
                                vitoriasAdversario++;
                            }
                        } else{
                        currentScreen = ENDING;
                        break;
                        }
            } break;
            case ENDING:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    countAdversario = 0;
                    countPokemon = 0;
                    vidas=3;
                    vidaAdversario = 3;
                    vitoriasJogador = 0;
                    vitoriasAdversario = 0;
                    meninaBool = false;
                    meninaBool = false;
                    cenario1bool = false;
                    cenario1boo2 = false;
                    cenario1boo3 = false;
                    cenario1boo4 = false;
                    jogador1jogou = true;
                    jogador2jogou =false;
                    tomouDano = false;

                    elapsedTimeAttackAd = 0.0f;
                    vectorAtaqueAd.x = 400;
                    vectorAtaqueAd.y = 110;
                    atacouAd = false;

                    elapsedTimeAttack = 0.0f;
                    vectorAtaque.x = 200;
                    vectorAtaque.y = 235;
                    atacouJog = false;

                    currentScreen = PressContinue;
                }
            } break;
        }

        BeginDrawing();
        ClearBackground(backgroundColor);

        switch(currentScreen)
        {
            case PressContinue:
            {
                if(IsSoundPlaying(vitoria))
                    StopSound(vitoria);

                if(!IsSoundPlaying(musicaMenu))
                    ResumeSound(musicaMenu);

                DrawTexture(texGifao,0,0,RAYWHITE);
                DrawTexture(bgMenu,0,0,RAYWHITE);
                DrawTexture(botaoPlay,145,285,RAYWHITE);
                DrawTexture(botaoInst,421,285,RAYWHITE);

            } break;

            case Instrucoes:
            {
                    DrawTexture(texGifaoBlur,0,0,RAYWHITE);
                    DrawTexture(bgMenuInst,0,0,RAYWHITE);
                    DrawTexture(botaoMenu,297,403,RAYWHITE);
             } break;

            case Cenario:
            {
                DrawTexture(cenarioSelect,0,0,RAYWHITE);
            } break;

            case Personagem:
            {
                DrawTexture(charSelect,0,0,RAYWHITE);
            } break;

            case GAMEPLAY:
            {

                Color textJOGADOR = GREEN;
                Color textADVERSARIO = GREEN;

                if(suporteDano <= 20)
                    textJOGADOR = RED;
                else if(suporteDano < 50)
                    textJOGADOR = YELLOW;
                else
                    textJOGADOR = GREEN;

                if(suporteDanoAd <= 20)
                    textADVERSARIO = RED;
                else if(suporteDanoAd < 50)
                    textADVERSARIO = YELLOW;
                 else
                    textADVERSARIO = GREEN;

                //DESENHA FUNDO
                if(cenario1bool){
                    DrawTexture(cen1tex, 0, 0, WHITE);
                    StopSound(musicaMenu);
                    ResumeSound(musicaBatalha1);
                } else if(cenario1boo2){
                     DrawTexture(cen2tex, 0, 0, WHITE);
                     StopSound(musicaMenu);
                    ResumeSound(musicaBatalha2);
                } else if(cenario1boo3){
                     DrawTexture(cen3tex, 0, 0, WHITE);
                     StopSound(musicaMenu);
                     ResumeSound(musicaBatalha3);
                }else if(cenario1boo4){
                     DrawTexture(cen4tex, 0, 0, WHITE);
                     StopSound(musicaMenu);
                     ResumeSound(musicaBatalha4);
                }

                DrawTexture(healthBarP1, 0, 15, WHITE);
                DrawTexture(healthBarP2, 524, 15, WHITE);

                //DESENHA PERSONAGEM DE ACORDO COM A ESCOLHA
                if(meninaBool){
                    DrawTexture(meninaPrincipal, 20,265, WHITE);
                    DrawTexture(meninoSecundario, 700,165, WHITE);
                } else {
                    DrawTexture(meninoPrincipal, 20,265, WHITE);
                    DrawTexture(meninaSecundario, 700,165, WHITE);
                }

                //DESENHA A VIDA E A QTD DE POKEMONS
                DrawText(TextFormat("Pokemons: %i",vidas),34,30,22,WHITE);
                DrawText(TextFormat("Pokemons: %i",vidaAdversario),626,30,22,WHITE);
                DrawText(TextFormat("%i",suporteDano),4,54,21,textJOGADOR);
                DrawText(TextFormat("%i",suporteDanoAd),756,54,21,textADVERSARIO);

                if(jogador1jogou)
                {
                    DrawTexture(timerP1, 295,10, WHITE);
                } else if(!jogador2jogou){
                    DrawTexture(timerP2, 295,10, WHITE);
                }


                if(tomouDano)
                {
                    elapsedTime += GetFrameTime();

                    if (elapsedTime < displayTime)
                    {
                        DrawTextEx(fonte,TextFormat("-%d", danoJog), posicaoPokemon,20, 2,RED);
                        DrawTextEx(fonte,TextFormat("-%d", danoAd), posicaoPokemonAd,20,2,RED);
                    }
                    else{
                        tomouDano = false;
                        elapsedTime = 0.0f;
                    }
                }

                if(atacouJog)
                {
                    vectorAtaque.x += 4.2;
                    vectorAtaque.y -= 2.0;

                    elapsedTimeAttack += GetFrameTime();

                    if (elapsedTimeAttack < displayAttack)
                    {
                        if(codAtaque == 1){
                         DrawTextureV(ataqueFogo, vectorAtaque, WHITE);
                        } else if(codAtaque == 2){
                        DrawTextureV(ataqueAgua, vectorAtaque, WHITE);
                        } else if(codAtaque == 3){
                        DrawTextureV(ataqueTerra, vectorAtaque, WHITE);
                        } else if(codAtaque == 4){
                        DrawTextureV(ataqueAr, vectorAtaque, WHITE);
                        }

                    }else {
                        elapsedTimeAttack = 0.0f;
                        vectorAtaque.x = 200;
                        vectorAtaque.y = 280;
                        atacouJog = false;
                    }
                }

                if(atacouAd)
                {
                    vectorAtaqueAd.x -= 4.2;
                    vectorAtaqueAd.y += 1.7;

                    elapsedTimeAttackAd += GetFrameTime();

                    if (elapsedTimeAttackAd < displayAttackAd)
                    {
                        if(codAtaqueAd == 1){
                         DrawTextureV(ataqueFogoAd, vectorAtaqueAd, WHITE);
                        }else if(codAtaqueAd == 2){
                        DrawTextureV(ataqueAguaAd, vectorAtaqueAd, WHITE);
                        }else if(codAtaqueAd == 3){
                        DrawTextureV(ataqueTerraAd, vectorAtaqueAd, WHITE);
                        }else if(codAtaqueAd == 4){
                        DrawTextureV(ataqueArAd, vectorAtaqueAd, WHITE);
                        }

                    }else {
                        elapsedTimeAttackAd = 0.0f;
                        vectorAtaqueAd.x = 500;
                        vectorAtaqueAd.y = 200;
                        atacouAd = false;
                    }
                }



                DrawTexture(atkFire, 10,405, WHITE);
                DrawTexture(atkWater, 203,405, WHITE);
                DrawTexture(atkGrass, 397,405, WHITE);
                DrawTexture(atkAir, 590,405, WHITE);

                if(jogador1jogou)
                {

                    if(CheckCollisionPointRec(GetMousePosition(), retanguloFogo) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouJog = true;
                        jogador1jogou = false;
                        codAtaque = 1;
                    }
                    if(CheckCollisionPointRec(GetMousePosition(), retanguloAgua) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouJog = true;
                        jogador1jogou = false;
                        codAtaque = 2;
                    }
                    if(CheckCollisionPointRec(GetMousePosition(), retanguloGrama) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouJog = true;
                        jogador1jogou = false;
                        codAtaque = 3;
                    }
                    if(CheckCollisionPointRec(GetMousePosition(), retanguloAr) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouJog = true;
                        jogador1jogou = false;
                        codAtaque = 4;
                    }
                }
                else if(!jogador2jogou)
                {
                    if(CheckCollisionPointRec(GetMousePosition(), retanguloFogo) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouAd = true;
                        jogador2jogou = true;
                        codAtaqueAd = 1;
                    }
                    if(CheckCollisionPointRec(GetMousePosition(), retanguloAgua) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouAd = true;
                        jogador2jogou = true;
                        codAtaqueAd = 2;
                    }
                    if(CheckCollisionPointRec(GetMousePosition(), retanguloGrama) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouAd = true;
                        jogador2jogou = true;
                        codAtaqueAd = 3;
                    }
                    if(CheckCollisionPointRec(GetMousePosition(), retanguloAr) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        atacouAd = true;
                        jogador2jogou = true;
                        codAtaqueAd = 4;
                    }
                }


                if(!jogador1jogou && jogador2jogou)
                {
                    tomouDano = true;

                    //Seção de Ataques: Fogo (dá super efetivo em grama e ar, toma o dobro de água)

                    if(codAtaque == 1 && codAtaqueAd == 1)
                    {
                        danoJog = rAd->danoAtaqueFogo * 0;
                        danoAd = r->danoAtaqueFogo * 0;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 1 && codAtaqueAd == 2)
                    {
                        danoJog = rAd->danoAtaqueAgua * 1;
                        danoAd =  r->danoAtaqueFogo * 0.10;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 1 && codAtaqueAd == 3)
                    {
                        danoJog = rAd->danoAtaqueGrama * 0.10;
                        danoAd = r->danoAtaqueFogo * 1;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 1 && codAtaqueAd == 4)
                    {
                        danoJog = rAd->danoAtaqueAr * 0.10;
                        danoAd = r->danoAtaqueFogo * 1;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }

                    //Seção de Ataques: Água (dá super efetivo em fogo, toma o dobro de grama)

                    if(codAtaque == 2 && codAtaqueAd == 1)
                    {
                        danoJog = rAd->danoAtaqueFogo * 0.10;
                        danoAd = r->danoAtaqueAgua * 1;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 2 && codAtaqueAd == 2)
                    {
                        danoJog = rAd->danoAtaqueAgua * 0;
                        danoAd = r->danoAtaqueAgua * 0;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 2 && codAtaqueAd == 3)
                    {
                        danoJog =rAd->danoAtaqueGrama * 1;
                        danoAd = r->danoAtaqueAgua * 0.10;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 2 && codAtaqueAd == 4)
                    {
                        danoJog = rAd->danoAtaqueAr * 0.50;
                        danoAd = r->danoAtaqueAgua * 0.50;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }

                    //Seção de Ataques: Grama (dá super efetivo em água, toma o dobro de fogo e ar)

                    if(codAtaque == 3 && codAtaqueAd == 1)
                    {
                        danoJog = rAd->danoAtaqueFogo * 1;
                        danoAd = r->danoAtaqueGrama * 0.10;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 3 && codAtaqueAd == 2)
                    {
                        danoJog = rAd->danoAtaqueAgua * 0.10;
                        danoAd=r->danoAtaqueGrama * 1;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 3 && codAtaqueAd == 3)
                    {
                        danoJog = rAd->danoAtaqueGrama * 0;
                        danoAd = r->danoAtaqueGrama * 0;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 3 && codAtaqueAd == 4)
                    {
                        danoJog = rAd->danoAtaqueAr * 1;
                        danoAd = r->danoAtaqueGrama * 0.10;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }

                    //Seção de Ataques: Ar (dá super efetivo em grama, toma o dobro de fogo)

                    if(codAtaque == 4 && codAtaqueAd == 1)
                    {
                        danoJog = rAd->danoAtaqueFogo * 1;
                        danoAd = r->danoAtaqueAr * 0.10;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 4 && codAtaqueAd == 2)
                    {
                        danoJog = rAd->danoAtaqueAgua * 0.50;
                        danoAd = r->danoAtaqueAr * 0.50;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 4 && codAtaqueAd == 3)
                    {
                        danoJog = rAd->danoAtaqueGrama * 0.10;
                        danoAd = r->danoAtaqueAr * 1;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }
                    if(codAtaque == 4 && codAtaqueAd == 4)
                    {
                        danoJog = rAd->danoAtaqueAr * 0;
                        danoAd = r->danoAtaqueAr * 0;
                        suporteDanoAd = suporteDanoAd - danoAd;
                        suporteDano = suporteDano - danoJog;
                    }

                    //==================================================================


                    jogador1jogou = true;
                    jogador2jogou = false;
                }


            switch(currentPoke)
            {
                case P1:
                    {
                        r = retiraPokemonJogador(&fila,0); //RETIRA O PRIMEIRO POKEMON JOGADOR

                        if(r->codBicho == 0){
                        DrawTextureV(pokemonJog1, posicaoPokemon, WHITE);
                        }else if(r->codBicho == 1){
                            DrawTextureV(pokemonJog2, posicaoPokemon, WHITE);
                        }else if(r->codBicho == 2){
                            DrawTextureV(pokemonJog3, posicaoPokemon, WHITE);
                        }

                    } break;
                case P2:
                    {
                        r = retiraPokemonJogador(&fila,1); //RETIRA O PRIMEIRO POKEMON JOGADOR
                        if(r->codBicho == 0){
                        DrawTextureV(pokemonJog1, posicaoPokemon, WHITE);
                        }else if(r->codBicho == 1){
                            DrawTextureV(pokemonJog2, posicaoPokemon, WHITE);
                        }else if(r->codBicho == 2){
                            DrawTextureV(pokemonJog3, posicaoPokemon, WHITE);
                        }
                    } break;
                case P3:
                    {
                        r = retiraPokemonJogador(&fila,2); //RETIRA O PRIMEIRO POKEMON JOGADOR
                        if(r->codBicho == 0){
                        DrawTextureV(pokemonJog1, posicaoPokemon, WHITE);
                        }else if(r->codBicho == 1){
                            DrawTextureV(pokemonJog2, posicaoPokemon, WHITE);
                        }else if(r->codBicho == 2){
                            DrawTextureV(pokemonJog3, posicaoPokemon, WHITE);
                        }
                    } break;
            }

            switch(currentAdversario)
            {
                case Ad1:
                    {
                        rAd = retiraPokemonAdversario(&filaAd,0); //RETIRA O PRIMEIRO POKEMON ADVERSARIO

                        if(rAd->codBicho == 0){
                            DrawTextureV(pokemonAd1, posicaoPokemonAd, WHITE);
                        }else if(rAd->codBicho == 1){
                            DrawTextureV(pokemonAd2, posicaoPokemonAd, WHITE);
                        }else if(rAd->codBicho == 2){
                            DrawTextureV(pokemonAd3, posicaoPokemonAd, WHITE);
                        }
                } break;

                case Ad2:
                    {
                        rAd = retiraPokemonAdversario(&filaAd,1); //RETIRA O PRIMEIRO POKEMON ADVERSARIO

                        if(rAd->codBicho == 0){
                            DrawTextureV(pokemonAd1, posicaoPokemonAd, WHITE);
                        }else if(rAd->codBicho == 1){
                            DrawTextureV(pokemonAd2, posicaoPokemonAd, WHITE);
                        }else if(rAd->codBicho == 2){
                            DrawTextureV(pokemonAd3, posicaoPokemonAd, WHITE);
                        }
                } break;

                case Ad3:
                    {

                        rAd = retiraPokemonAdversario(&filaAd,2); //RETIRA O PRIMEIRO POKEMON ADVERSARIO

                        if(rAd->codBicho == 0){
                            DrawTextureV(pokemonAd1, posicaoPokemonAd, WHITE);
                        }else if(rAd->codBicho == 1){
                            DrawTextureV(pokemonAd2, posicaoPokemonAd, WHITE);
                        }else if(rAd->codBicho == 2){
                            DrawTextureV(pokemonAd3, posicaoPokemonAd, WHITE);
                        }
                        } break;
                }

            } break;
            case ENDING:
            {
               if(vitoriasJogador > vitoriasAdversario)
               {
                   if(IsSoundPlaying(musicaBatalha1))
                        StopSound(musicaBatalha1);
                   if(IsSoundPlaying(musicaBatalha2))
                        StopSound(musicaBatalha2);
                   if(IsSoundPlaying(musicaBatalha3))
                        StopSound(musicaBatalha3);
                   if(IsSoundPlaying(musicaBatalha4))
                        StopSound(musicaBatalha4);

                   ResumeSound(vitoria);
                   DrawTexture(endingP1,0,0,WHITE);
               } else{
                   if(IsSoundPlaying(musicaBatalha1))
                        StopSound(musicaBatalha1);
                   if(IsSoundPlaying(musicaBatalha2))
                        StopSound(musicaBatalha2);
                   if(IsSoundPlaying(musicaBatalha3))
                        StopSound(musicaBatalha3);
                   if(IsSoundPlaying(musicaBatalha4))
                        StopSound(musicaBatalha4);

                   ResumeSound(vitoria);
                   DrawTexture(endingP2,0,0,WHITE);
               }
            } break;
        }

        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    UnloadTexture(bgMenu);
    UnloadTexture(bgMenuInst);
    UnloadTexture(texGifao);
    UnloadTexture(texGifaoBlur);
    UnloadImage(menuGif);
    UnloadImage(menuGifBlur);

    UnloadTexture(botaoPlay);
    UnloadTexture(botaoInst);
    UnloadTexture(botaoMenu);

    UnloadTexture(charSelect);

    UnloadTexture(healthBarP1);
    UnloadTexture(healthBarP2);
    UnloadTexture(timerP1);
    UnloadTexture(timerP2);

    UnloadTexture(atkFire);
    UnloadTexture(atkWater);
    UnloadTexture(atkGrass);
    UnloadTexture(atkAir);

    UnloadTexture(cen1tex);
    UnloadTexture(cen2tex);
    UnloadTexture(cen3tex);
    UnloadTexture(cen4tex);

    UnloadTexture(meninaPrincipal);
    UnloadTexture(meninaSecundario);
    UnloadTexture(meninoPrincipal);
    UnloadTexture(meninoSecundario);

    UnloadTexture(pokemonJog1);
    UnloadTexture(pokemonJog2);
    UnloadTexture(pokemonJog3);

    UnloadTexture(pokemonAd1);
    UnloadTexture(pokemonAd2);
    UnloadTexture(pokemonAd3);

    UnloadTexture(endingP1);
    UnloadTexture(endingP2);

    UnloadSound(musicaMenu);
    UnloadSound(vitoria);
    UnloadSound(musicaBatalha1);
    UnloadSound(musicaBatalha2);
    UnloadSound(musicaBatalha3);
    UnloadSound(musicaBatalha4);

    CloseAudioDevice();

    CloseWindow();
    return 0;
}
