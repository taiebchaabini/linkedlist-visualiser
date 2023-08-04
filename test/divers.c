#include "main.h"

void write_json_to_file(list_t *data, unsigned int is_single)
{
    FILE *fp;

    // Open the file in write mode
    fp = fopen("data.json", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", "data.json");
        return;
    }

    // Start writing the JSON
    fprintf(fp, "{\n");

    // Write the key-value pairs
    int i = 0;
    while (data)
    {
        fprintf(fp, "\t\"%p\": {\n\t\t\"Label\": \"%s\",", data, data->str);
        fprintf(fp, "\n\t\t\"Next\": \"%p\"", data->next);

        // if (is_single == 0)
        // {
        //     // fprintf(fp, ",\n\t\t\"Prev\": \"%p\"\n\t", data->prev);
        // }
        // else
        // {
        fprintf(fp, "\n\t");
        // }
        fprintf(fp, "}");

        if (data->next != NULL)
            fprintf(fp, ",\n");
        // if (is_single == 0)
        // {
        //     if (data->prev != NULL)
        //         fprintf(fp, ",\n");
        // }

        data = data->next;
    }

    // End the JSON
    fprintf(fp, "\n}\n");

    // Close the file
    fclose(fp);
}
