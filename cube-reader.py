import cv2

cap = cv2.VideoCapture(0)

cap.set(3, 768)
cap.set(4, 768)

sides = ['front','right','left','back','up','down']
i = 0
while(i < len(sides)):
    str = input(f'Position the {sides[i]} side towards the camera and press ENTER.')
    ret, frame = cap.read()
    print("Press y to save photo, r to retry.")
    while(True):
        cv2.imshow(sides[i], frame) # display image
        if cv2.waitKey(0) & 0xFF == ord('r'):
            print('Retrying.')
            cv2.destroyAllWindows()
            break
        if cv2.waitKey(0) & 0xFF == ord('y'):
            cv2.imwrite(f'cube-faces/' + sides[i] + '.png', frame)
            print("Save successful.")
            cv2.destroyAllWindows()
            i += 1
            break

cap.release()
