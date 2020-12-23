const TodoList = artifacts.require('./TodoList.sol')

contract('TodoList', (accounts) => {
	before(async () => {
		this.todoList = await TodoList.deployed()
	})
	it('pasileidzia teisingai', async () => {
		const address = await this.todoList.address
		assert.notEqual(address, 0x0)
		assert.notEqual(address, '')
		assert.notEqual(address, null)
		assert.notEqual(address, undefined)
	})
	it('vardija kontraktus', async () => {
   		const taskCount = await this.todoList.taskCount()
		const task = await this.todoList.tasks(taskCount)
		assert.equal(task.id.toNumber(), taskCount.toNumber())
		assert.equal(task.content, 'Testas')
		assert.equal(task.complete, undefined)
		assert.equal(taskCount.toNumber(), 1)
	})
	it('sukuria kontraktus', async () =>{
		const result = await this.todoList.createTask('Naujas kontraktas')
		const taskCount = await this.todoList.taskCount()
		assert.equal(taskCount, 2)
		const event = result.logs[0].args
		console.log(result)
		assert.equal(event.id.toNumber(), 2)
		assert.equal(event.content, 'Naujas kontraktas')
		assert.equal(event.completed, false)
	})
	it('slepia ivykdytus kontraktus', async() => {
		const result = await this.todoList.toggleCompleted(1)
		const task = await this.todoList.tasks(1)
		assert.equal(task.completed, true)
		const event = result.logs[0].args
		assert.equal(event.id.toNumber(), 1)
		assert.equal(event.completed, true)
	})
})