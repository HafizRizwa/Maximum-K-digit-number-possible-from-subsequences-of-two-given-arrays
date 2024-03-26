#include <iostream>
using namespace std;
void pop_front(int arr[], int& size) {
    if (size > 0) {
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void maxNumber(int nums1[], int len1, int nums2[], int len2, int k) {
    int result[k];
    int resultIndex = 0;

    int s1Start = max(0, k - len2);
    int s1End = min(k, len1);

    for (int s1 = s1Start; s1 <= s1End; s1++) {
        int p1[s1];
        int p2[k - s1];
        int p1Index = 0, p2Index = 0;

        for (int i = 0; i < len1; i++) {
            while (p1Index > 0 && p1[p1Index - 1] < nums1[i] && (len1 - i) > (s1 - p1Index)) {
                p1Index--;
            }

            if (p1Index < s1) {
                p1[p1Index++] = nums1[i];
            }
        }

        for (int i = 0; i < len2; i++) {
            while (p2Index > 0 && p2[p2Index - 1] < nums2[i] && (len2 - i) > (k - s1 - p2Index)) {
                p2Index--;
            }

            if (p2Index < k - s1) {
                p2[p2Index++] = nums2[i];
            }
        }

        int temp[k];
        int tempIndex = 0;
        for (int j = 0; j < k; j++) {
            if (p1Index > 0 && p2Index > 0) {
                if (p1[0] > p2[0]) {
                    temp[tempIndex++] = p1[0];
                    pop_front(p1, p1Index);
                } else {
                    temp[tempIndex++] = p2[0];
                    pop_front(p2, p2Index);
                }
            } else if (p1Index > 0) {
                temp[tempIndex++] = p1[0];
                pop_front(p1, p1Index);
            } else if (p2Index > 0) {
                temp[tempIndex++] = p2[0];
                pop_front(p2, p2Index);
            }
        }

        if (resultIndex == 0) {
            for (int j = 0; j < k; j++) {
                result[j] = temp[j];
            }
            resultIndex = k;
        } else {
            for (int j = 0; j < k; j++) {
                if (temp[j] > result[j]) {
                    for (int l = 0; l < k; l++) {
                        result[l] = temp[l];
                    }
                    break;
                } else if (temp[j] < result[j]) {
                    break;
                }
            }
        }
    }

    cout << "Output: [";
    for (int i = 0; i < k; i++) {
        cout << result[i];
        if (i < k - 1) {
        cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
	int len1;
	    int len2;
	    	cin>>len1;
	    	    cin>>len2;
	int arr1[len1];
	int arr2[len2];

	for(int i=0;i<len1;i++)
	{
		cin>>arr1[i];
	}

    for(int j=0;j<len2;j++)
	{
		cin>>arr2[j];
	}
    int k;
    cin>>k;

    maxNumber(arr1, len1, arr2, len2, k); // Output: [9, 8, 6, 5, 3]

    return 0;
}
