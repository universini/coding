class member(object):
    def __init__(self, first, last):
        self.first = first
        self.last = last

    def __str__(self):
        return self.first + self.last

    def get_member(self):
        return self.first + self.last

class member_info(object):
    def __init__(self, first, last, phone):
        member.__init__(self, first, last)
        self.phone = phone

    def get_member_info(self):
        return self.first + self.last + self.phone


if __name__ == '__main__':

    m1 = member('sidde ', 'gowda ')
    m2 = member('nanditha ', 'gowda ')
    i1 = member_info('sidde ', 'gowda ', '408 338 9388')
    i2 = member_info('nanditha ', 'gowda ', '408 722 6455')

    print(m1) #__str__
    print(m2) #__str__

    print(m1.get_member())
    print(i1.get_member_info())
    print(m2.get_member())
    print(i2.get_member_info())
