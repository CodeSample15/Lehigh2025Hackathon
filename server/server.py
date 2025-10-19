'''
    Error codes:
        - NOVAL = requested variable not found
        - NOPER = no permission to get variable
'''

class ServerState:
    def __init__(self):
        self.public_vars = {}
        self.private_vars = {}

        self.changes = {}
    
    def add_var(self, varName, defaultValue):
        self.public_vars[varName] = defaultValue

    def add_obj(self, objName, objData):
        pass

    def get_var(self, name):
        return self.public_vars.get(name, 'NOVAL')

    def flush_changes(self):
        self.changes = {}

class ServerObject:
    def __init__(self, owner, json):
        pass