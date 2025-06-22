from flask import Flask, request
from ultralytics import YOLO
from PIL import Image

app = Flask(__name__)
model = YOLO('yolov8n.pt')  # Automatically downloads on first run

@app.route('/detect', methods=['POST'])
def detect():
    image = request.files['image']
    img = Image.open(image).convert("RGB")
    results = model.predict(img, verbose=False)
    labels = [results[0].names[int(cls)] for cls in results[0].boxes.cls]
    return ', '.join(set(labels)) or "No objects detected"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
