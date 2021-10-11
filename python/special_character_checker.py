import re


def isCharacter(txt):

    reg = re.compile('[@_!#$%^&*()<>?/\|}{~:]')

    if(reg.search(txt) == None):
        print("Given string not includes special characters.")

    else:
        print("Given String incudes special characters.")


if __name__ == '__main__':

    txt = "hello@@@World!!"

    isCharacter(txt)
