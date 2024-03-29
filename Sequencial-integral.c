#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define e 2.71828

double calculaArea(double pontoA, double pontoB);
double calculaPMedio(double pontoA, double pontoB);
double calculaIntegral(double pontoA, double pontoB,double erro);
double Modulo(double num);
double func(double x);
int funcNum = 0;
double resultadoFinal = 0.0;

// Calcula a área de um retângulo
double calculaArea(double pontoA, double pontoB){
    return ((pontoB - pontoA) * func(pontoB));
}

// Calcula o ponto médio 
double calculaPMedio(double pontoA, double pontoB){
    return (pontoB + pontoA)/2;
}

double calculaIntegral(double pontoA, double pontoB, double erro){
    double pontoMedio = calculaPMedio(pontoA, pontoB);
    double retanguloEsq = calculaArea(pontoA, pontoMedio);
    double retanguloDir = calculaArea(pontoMedio, pontoB);
    double retanguloMaior = calculaArea(pontoA, pontoB);
    double errinho = retanguloMaior - (retanguloEsq + retanguloDir);
    if(Modulo(errinho) < erro ){
        return retanguloDir+retanguloEsq;
    }
    else{
        return calculaIntegral(pontoA, pontoMedio, erro) + calculaIntegral(pontoMedio, pontoB, erro);
    }
}

//Função que substitui o abs() pois este nao suporta double.
double Modulo(double num){
    if(num < 0)
        num = num * (-1);
    return num;
}

// Retorna a função f(x) 
double func(double x) {
    switch(funcNum){
        case 0:
            return (1 + x);
            break;
        case 1:
            return (sqrt(1 - pow(x,2)));
            break;
        case 2:
            return (sqrt(1 + pow(x,4)));
            break;
        case 3:
            return  sin(pow(x,2));
            break;
        case 4:
            return  cos(pow(e, -x));
            break;
        case 5:
            return  (cos(pow(e, -x)) * x);
            break;
        case 6:
            return (cos(pow(e, -x)) * (0.005 * pow(x,3)));
            break;
    }
}

    int main(){
        double pontoA, pontoB, erro;

        printf("Digite a funcao desejada a ser integrada:\n(0) f(x) = 1 + x,\n(1) f(x) = sqrt(1 - pow(x, 2)), -1 < x < 1,\n(2) f(x) = sqrt(1 + pow(x, 4)),\n(3) f(x) = sin(pow(x, 2)),\n(4) f(x) = cos(pow(e, -x)),\n(5) f(x) = cos(pow(e, -x)) * x,\n(6) f(x) = cos(pow(e, -x)) * (0.005 * pow(x, 3) + 1).\n");
        scanf("%d", &funcNum);

        if(funcNum < 0 || funcNum > 6){
            printf("Opcao invalida.\n");
            return 0;
        }

        printf("Digite o limite de integração inicial:\n");
        scanf("%lf", &pontoA);

        printf("Digite o limite de integração final:\n");
        scanf("%lf", &pontoB);

        printf("Digite o erro máximo aceitável:\n");
        scanf("%lf", &erro);

        //Segunda função não é real se x estiver fora do intervalo -1 < x < 1
        if(funcNum == 1 && (pontoA <= -1 || pontoB >= 1 || pontoA >= 1 || pontoB <= -1)){
            printf("Limites não aceitos pela função!\n");
            return 0;
        }

        resultadoFinal = calculaIntegral(pontoA, pontoB, erro);
        printf("Resultado Final é: %lf\n", &resultadoFinal);
    }
