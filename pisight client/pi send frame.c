#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define IMG_URL "http://192.168.0.127:8080/shot.jpg"         //phone IP
#define SERVER_URL "http://192.168.0.224:5000/detect"        //PC IP
#define IMAGE_NAME "frame.jpg"

void capture_image() {
    printf("[INFO] Capturing image from IP webcam...\n");
    char command[256];
    snprintf(command, sizeof(command), "wget -q %s -O %s", IMG_URL, IMAGE_NAME);
    int ret = system(command);
    if (ret != 0) {
        printf("[ERROR] Failed to capture image.\n");
    }
}

void send_to_server_and_speak() {
    printf("[INFO] Sending image to server...\n");

    FILE *fp;
    char buffer[1024];
    char command[256];

    snprintf(command, sizeof(command), "curl -s -X POST -F \"image=@%s\" %s", IMAGE_NAME, SERVER_URL);

    fp = popen(command, "r");
    if (fp == NULL) {
        printf("[ERROR] Failed to run curl command.\n");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("[DETECTED] %s\n", buffer);
        char speak_cmd[256];
        snprintf(speak_cmd, sizeof(speak_cmd), "espeak 'Detected %s' --stdout | aplay", buffer);
        system(speak_cmd);
    } else {
        printf("[ERROR] No response from server.\n");
    }

    pclose(fp);
}

int main() {
    while (1) {
        capture_image();
        send_to_server_and_speak();
        sleep(5);  
    }
    return 0;
}
