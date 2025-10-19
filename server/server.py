'''
    Error codes:
        - NOVAL = requested variable not found
        - NOPER = no permission to get variable
'''

class ServerState:
    def __init__(self):
        self.reset()

    def reset(self):
        self.public_vars = {}
        self.private_vars = {}
        self.object_templates = {}
        self.objects = {}

        self.changes = {}

    def add_var(self, varName, defaultValue):
        self.public_vars[varName] = defaultValue

    def add_obj(self, objName, objData):
        self.object_templates[objName] = objData

    def register_new_object(self, objName, owner_uuid):
        '''
            Register a new server object with ownership to a specific connection uuid
            Returns true if the instantiation was successful, False otherwise
        '''

        template = self.object_templates.get(objName, None)

        if template:
            owned_objects = self.objects.get(owner_uuid, [])
            owned_objects.append({objName, template.copy()})
            self.objects[owner_uuid] = owned_objects


        return False

    def disconnect(self, uuid):
        pass

    def get_var(self, name):
        return self.public_vars.get(name, 'NOVAL')

    def flush_changes(self):
        self.changes = {}