import cv2
from sys import exit

#Decommissioned but not deleted incase we need to roll back
def capture_faces():
    cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 768)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 768)

    sides = ['F','R','B','L','U','D']
    sides_taken = []
    i = 0
    while(i < len(sides)):
        while(True):
            ret, frame = cap.read()
            frame = cv2.resize(frame, (768, 768))
            cv2.imshow(sides[i], frame) # display image
            if cv2.waitKey(1) & 0xFF == ord('y'):
                ret, frame = cap.read()
                frame = cv2.resize(frame, (768, 768)) #resizing so it works with algorithm
                cv2.convertScaleAbs(frame, 1.7, 70) #increase contrast and brightness to improve consistency
                cv2.imshow(sides[i], frame)
                cv2.imwrite(f'cube-faces/' + sides[i] + '.png', frame)
                print(f"Successfully saved {sides[i]}.")
                cv2.destroyAllWindows()
                i += 1
                break

    cap.release()
    cv2.destroyAllWindows()

#current implementation
def capture_faces_v2():
    cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 768)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 768)

    sides_taken = []
    while(len(sides_taken) < 6):
        while(True):
            save = False
            ret, frame = cap.read()
            frame = cv2.resize(frame, (768, 768))
            cv2.imshow("video", frame) # display current video
            pressedKey = cv2.waitKey(25) & 0xFF

            if pressedKey == ord('f'): saveTo = 'F'; save = True #checking which face to save
            elif pressedKey == ord('r'): saveTo = 'R'; save = True
            elif pressedKey == ord('b'): saveTo = 'B'; save = True
            elif pressedKey == ord('l'): saveTo = 'L'; save = True
            elif pressedKey == ord('u'): saveTo = 'U'; save = True
            elif pressedKey == ord('d'): saveTo = 'D'; save = True
            elif pressedKey == 27:
                cv2.destroyAllWindows()
                cap.release()
                exit()
            
            if (save):
                pic = frame
                pic = cv2.resize(pic, (768, 768)) #resizing so it works with algorithm
                cv2.convertScaleAbs(pic, 1.7, 70) #increase contrast and brightness to improve consistency
                cv2.imshow("video", pic) # display snapshot of video
                cv2.waitKey(1)
                cv2.imwrite(f'cube-faces/' + saveTo + '.png', pic)
                if saveTo not in sides_taken:
                    sides_taken.append(saveTo)
                    print(f"Successfully saved {saveTo}.")
                else:
                    print(f"Successfully overwrote {saveTo}.")
                cv2.destroyAllWindows()
                break

    print("Saved images to /cube-faces.")
    cap.release()
    cv2.destroyAllWindows()   

if __name__ == "__main__":
    capture_faces_v2()
