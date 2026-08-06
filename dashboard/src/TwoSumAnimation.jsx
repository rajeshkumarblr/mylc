import React, { useState } from 'react';

const steps = [
  {
    title: "Initial State",
    text: "We want to find two numbers in the array that add up to the target (9). We will use a Hash Map to store numbers we have seen so far.",
    arrayIdx: -1,
    mapData: {},
    action: "",
  },
  {
    title: "Step 1",
    text: "Look at the first element (2). To reach our target of 9, we need to find the complement: 9 - 2 = 7.",
    arrayIdx: 0,
    mapData: {},
    action: "calculate_complement",
  },
  {
    title: "Step 2",
    text: "Check if 7 is in our Hash Map. It's empty, so we haven't seen 7 yet.",
    arrayIdx: 0,
    mapData: {},
    action: "check_map",
  },
  {
    title: "Step 3",
    text: "Since we didn't find the complement, we add the current number (2) and its index (0) to the Hash Map.",
    arrayIdx: 0,
    mapData: { 2: 0 },
    action: "add_map",
  },
  {
    title: "Step 4",
    text: "Move to the next element (7). To reach our target of 9, the complement is: 9 - 7 = 2.",
    arrayIdx: 1,
    mapData: { 2: 0 },
    action: "calculate_complement",
  },
  {
    title: "Step 5",
    text: "Check if 2 is in our Hash Map. Yes, it is! We found our pair.",
    arrayIdx: 1,
    mapData: { 2: 0 },
    action: "check_map_success",
  },
  {
    title: "Finished!",
    text: "We return the index of the current element (1) and the index of the complement from the Hash Map (0). Result: [0, 1].",
    arrayIdx: 1,
    mapData: { 2: 0 },
    action: "done",
  }
];

export default function TwoSumAnimation() {
  const [currentStep, setCurrentStep] = useState(0);
  const step = steps[currentStep];
  
  const array = [2, 7, 11, 15];
  const target = 9;

  return (
    <div style={{ padding: '1rem', color: 'var(--text-main)', display: 'flex', flexDirection: 'column', gap: '2rem' }}>
      
      {/* Controls */}
      <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', background: 'rgba(255,255,255,0.05)', padding: '1rem', borderRadius: '8px' }}>
        <button 
          onClick={() => setCurrentStep(Math.max(0, currentStep - 1))}
          disabled={currentStep === 0}
          style={{ padding: '0.5rem 1rem', background: currentStep === 0 ? '#334155' : 'var(--accent-color)', color: '#fff', border: 'none', borderRadius: '4px', cursor: currentStep === 0 ? 'not-allowed' : 'pointer' }}
        >
          Previous Step
        </button>
        <div style={{ fontWeight: 'bold' }}>Step {currentStep + 1} of {steps.length}</div>
        <button 
          onClick={() => setCurrentStep(Math.min(steps.length - 1, currentStep + 1))}
          disabled={currentStep === steps.length - 1}
          style={{ padding: '0.5rem 1rem', background: currentStep === steps.length - 1 ? '#334155' : 'var(--accent-color)', color: '#fff', border: 'none', borderRadius: '4px', cursor: currentStep === steps.length - 1 ? 'not-allowed' : 'pointer' }}
        >
          Next Step
        </button>
      </div>

      {/* Explanation Text */}
      <div style={{ textAlign: 'center', minHeight: '60px' }}>
        <h3 style={{ margin: '0 0 0.5rem 0', color: '#7dd3fc' }}>{step.title}</h3>
        <p style={{ margin: 0, fontSize: '1.1rem' }}>{step.text}</p>
      </div>

      <div style={{ display: 'flex', gap: '2rem', flexWrap: 'wrap', justifyContent: 'center', alignItems: 'flex-start' }}>
        
        {/* Array Visualization */}
        <div style={{ flex: '1', minWidth: '300px', background: 'rgba(0,0,0,0.2)', padding: '1.5rem', borderRadius: '8px', border: '1px solid var(--border-color)' }}>
          <h4 style={{ margin: '0 0 1rem 0', textAlign: 'center' }}>Array (Target: {target})</h4>
          <div style={{ display: 'flex', gap: '0.5rem', justifyContent: 'center' }}>
            {array.map((num, idx) => {
              const isCurrent = step.arrayIdx === idx;
              const isComplementFound = step.action === 'done' && idx === 0; // Special highlight for the found pair
              return (
                <div key={idx} style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', gap: '0.5rem' }}>
                  <div style={{ color: 'var(--text-muted)', fontSize: '0.8rem' }}>Index {idx}</div>
                  <div style={{
                    width: '50px',
                    height: '50px',
                    display: 'flex',
                    alignItems: 'center',
                    justifyContent: 'center',
                    background: isCurrent ? '#60a5fa' : isComplementFound ? '#4ade80' : 'rgba(255,255,255,0.1)',
                    color: isCurrent || isComplementFound ? '#000' : '#fff',
                    fontWeight: 'bold',
                    fontSize: '1.2rem',
                    borderRadius: '8px',
                    transition: 'all 0.3s ease',
                    transform: isCurrent ? 'scale(1.1)' : 'scale(1)'
                  }}>
                    {num}
                  </div>
                  {isCurrent && <div style={{ fontSize: '1.5rem', color: '#60a5fa' }}>↑</div>}
                </div>
              );
            })}
          </div>
        </div>

        {/* Hash Map Visualization */}
        <div style={{ flex: '1', minWidth: '300px', background: 'rgba(0,0,0,0.2)', padding: '1.5rem', borderRadius: '8px', border: '1px solid var(--border-color)' }}>
          <h4 style={{ margin: '0 0 1rem 0', textAlign: 'center' }}>Hash Map</h4>
          <div style={{ display: 'flex', flexDirection: 'column', gap: '0.5rem' }}>
            {Object.keys(step.mapData).length === 0 ? (
              <div style={{ textAlign: 'center', color: 'var(--text-muted)', padding: '1rem', fontStyle: 'italic' }}>Map is empty</div>
            ) : (
              <table style={{ width: '100%', borderCollapse: 'collapse' }}>
                <thead>
                  <tr style={{ borderBottom: '1px solid rgba(255,255,255,0.1)' }}>
                    <th style={{ padding: '0.5rem', textAlign: 'left' }}>Key (Number)</th>
                    <th style={{ padding: '0.5rem', textAlign: 'left' }}>Value (Index)</th>
                  </tr>
                </thead>
                <tbody>
                  {Object.entries(step.mapData).map(([key, val]) => {
                    const isSuccess = step.action === 'check_map_success' || step.action === 'done';
                    return (
                      <tr key={key} style={{ 
                        background: isSuccess ? 'rgba(74, 222, 128, 0.2)' : 'rgba(255,255,255,0.05)',
                        transition: 'background 0.3s ease'
                      }}>
                        <td style={{ padding: '0.8rem', fontWeight: 'bold' }}>{key}</td>
                        <td style={{ padding: '0.8rem' }}>{val}</td>
                      </tr>
                    );
                  })}
                </tbody>
              </table>
            )}
          </div>
        </div>

      </div>

    </div>
  );
}
