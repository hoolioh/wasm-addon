const wasmAddon = require('../index')
const assert = require('assert')

assert(wasmAddon.track, "Expected function undefined")
assert(wasmAddon.equal, "Expected function undefined")

// No args
assert.strictEqual(wasmAddon.track(), null, "Unexpected value")
assert.strictEqual(wasmAddon.equal(), false, "Unexpected value")

// Normal behavior
const value = 'test'
const refToValue = 'test'
assert.strictEqual(wasmAddon.track(value), 'test', 'Unexpected value')
assert.strictEqual(wasmAddon.equal(refToValue), true, 'Unexpected value')

