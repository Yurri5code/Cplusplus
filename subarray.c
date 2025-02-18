long maxSubarrayValue(int arr_count, int* arr) {
    long maxValue = -1;
    long sumEven = 0,sumOdd = 0;
    int j = 0;
    for(int i = 0;i < arr_count;i++){
        for(int k = j; k < arr_count;k++){
            if(k%2 == 0){
                sumEven+=arr[k];
            }else{
                sumOdd += arr[k];
            }
        }
        long sumSquare = (sumEven - sumOdd)*(sumEven - sumOdd);
        if(sumSquare > maxValue){
            maxValue = sumSquare;
        }
        sumEven = 0;
        sumOdd = 0;
        j++;
    }
    return maxValue;
}

long maxValue = -1;
    long* sumEven = (long*)malloc((arr_count + 1) * sizeof(long));
    long* sumOdd = (long*)malloc((arr_count + 1) * sizeof(long));

    if (sumEven == NULL || sumOdd == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    sumEven[0] = 0;
    sumOdd[0] = 0;

    for (int i = 0; i < arr_count; ++i) {
        sumEven[i + 1] = sumEven[i] + (i % 2 == 0 ? arr[i] : 0);
        sumOdd[i + 1] = sumOdd[i] + (i % 2 != 0 ? arr[i] : 0);
    }

    for (int i = 0; i < arr_count; ++i) {
        for (int j = i; j < arr_count; ++j) {
            long evenSum = sumEven[j + 1] - sumEven[i];
            long oddSum = sumOdd[j + 1] - sumOdd[i];
            long sumSquare = (evenSum - oddSum) * (evenSum - oddSum);
            if (sumSquare > maxValue) {
                maxValue = sumSquare;
            }
        }
    }

    free(sumEven);
    free(sumOdd);

    return maxValue;
}

long maxSubarrayValue(int arr_count, int* arr) {
    long maxValue = -1;
    long* prefixEven = (long*)malloc((arr_count + 1) * sizeof(long));
    long* prefixOdd = (long*)malloc((arr_count + 1) * sizeof(long));

    if (prefixEven == NULL || prefixOdd == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    prefixEven[0] = 0;
    prefixOdd[0] = 0;

    for (int i = 0; i < arr_count; ++i) {
        prefixEven[i + 1] = prefixEven[i] + (i % 2 == 0 ? arr[i] : 0);
        prefixOdd[i + 1] = prefixOdd[i] + (i % 2 != 0 ? arr[i] : 0);
    }

    for (int i = 0; i < arr_count; ++i) {
        for (int j = i; j < arr_count; ++j) {
            long evenSum = prefixEven[j + 1] - prefixEven[i];
            long oddSum = prefixOdd[j + 1] - prefixOdd[i];
            long sumSquare = (evenSum - oddSum) * (evenSum - oddSum);
            if (sumSquare > maxValue) {
                maxValue = sumSquare;
            }
        }
    }

    free(prefixEven);
    free(prefixOdd);

    return maxValue;
}
