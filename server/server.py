class Server:
    def __init__(self):
        self.public_vars = {}
        self.private_vars = {}

        self.changes = {}
    
    def add_var(self, varJson):
        pass

    def flush_changes(self):
        self.changes = {}

class ServerObject:
    def __init__(self, json):
        pass