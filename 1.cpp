#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 5005
#define MAX_NAME_LENGTH 21
int parent[MAX_ITEMS];
int findParent(int item) {
    while (parent[item] != item)
        item = parent[item];
    return item;
}
int main() {
    int i, num_items, num_connections, j;
    char item_names[MAX_ITEMS][MAX_NAME_LENGTH];
    char First_item[MAX_NAME_LENGTH], Second_item[MAX_NAME_LENGTH];
    while (scanf("%d%d", &num_items, &num_connections)) {
        if (num_items == 0 && num_connections == 0) 
            break;
        int max_group_size = 0;
        for (i = 1; i <= num_items; i++) {
            scanf("%s", item_names[i]);
            parent[i] = i;
        }
        for (i = 0; i < num_connections; i++) {
            scanf("%s%s", First_item, Second_item);
            int item_idx = 0, connected_item_idx = 0;
            for (j = 1; j <= num_items; j++) {
                if (strcmp(First_item, item_names[j]) == 0) 
                    item_idx = j;
                if (strcmp(Second_item, item_names[j]) == 0) 
                    connected_item_idx = j;
            }
            parent[findParent(item_idx)] = findParent(connected_item_idx);
        }
        int group_size[MAX_ITEMS] = {0};
        for (i = 1; i <= num_items; i++) {
            parent[i] = findParent(i);
            group_size[parent[i]]++;
            max_group_size = (max_group_size > group_size[parent[i]]) ? max_group_size : group_size[parent[i]]; // Update the maximum size
        }
        printf("%d\n", max_group_size);
    }
    return 0;
}
