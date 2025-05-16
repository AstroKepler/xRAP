import math
import time
import random
import numpy as np
from PIL import Image
from tqdm import tqdm

def initialise_height():
    # Load heightmap image and convert to grayscale.
    img = Image.open("heightmap.png").convert("L")
    # Resize image to match grid size.
    img_resized = img.resize((256, 256), Image.LANCZOS)
    # Convert image to numpy array and normalize to [0, self.max_height].
    pixel_values = np.array(img_resized).astype(np.float32)
    pixel_values = (pixel_values / 255.0) * 1821
    # Create an image for visualization (normalized back to 0-255).
    normalized_for_image = (pixel_values / 1821 * 255.0).astype(np.uint8)
    img_output = Image.fromarray(normalized_for_image, mode='L')
    img_output.save("HEIGHT_DATA.png")
    print("HEIGHT_DATA.png saved")

if __name__ == "__main__":
    initialise_height()