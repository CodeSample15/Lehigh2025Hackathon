'''
    Error codes
'''

class Server:
    def __init__(self):
        self.public_vars = {}
        self.private_vars = {}

        self.changes = {}
    
    def add_var(self, varJson):
        pass

    def get_var(self, name):
        return self.public_vars[name]

    def flush_changes(self):
        self.changes = {}

class ServerObject:
    def __init__(self, json):
        pass