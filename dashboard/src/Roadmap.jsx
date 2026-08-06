import React, { useMemo, useState } from 'react';
import { ReactFlow, Controls, Background, Handle, Position, useReactFlow, ReactFlowProvider } from '@xyflow/react';
import '@xyflow/react/dist/style.css';

const CategoryNode = ({ data }) => {
  const isTB = data.layout === 'TB';
  
  return (
    <div 
      title={`${data.solved}/${data.total} problems solved. Great job, keep up the momentum!`}
      onClick={() => data.onCategoryClick && data.onCategoryClick(data.label)}
      style={{
      background: 'rgba(30, 41, 59, 0.95)',
      border: '1px solid var(--border-color)',
      borderRadius: '6px',
      padding: '0',
      minWidth: '160px',
      boxShadow: '0 4px 6px -1px rgba(0, 0, 0, 0.5)',
      color: 'var(--text-main)',
      fontSize: '0.85rem',
      fontWeight: '500',
      overflow: 'hidden',
      cursor: 'pointer'
    }}>
      <Handle 
        type="target" 
        position={isTB ? Position.Top : Position.Left} 
        style={{ background: '#94a3b8', border: 'none' }} 
      />
      
      <div style={{ padding: '0.5rem 1rem', textAlign: 'center' }}>
        {data.label}
      </div>
      
      {data.total > 0 && (
        <div style={{ 
          background: 'rgba(0,0,0,0.4)', 
          height: '6px', 
          width: '100%',
          borderTop: '1px solid rgba(255,255,255,0.05)'
        }}>
          <div style={{
            background: data.solved === data.total ? '#4ade80' : '#60a5fa',
            height: '100%',
            width: `${(data.solved / data.total) * 100}%`,
            transition: 'width 0.3s ease'
          }}></div>
        </div>
      )}

      <Handle 
        type="source" 
        position={isTB ? Position.Bottom : Position.Right} 
        style={{ background: '#94a3b8', border: 'none' }} 
      />
    </div>
  );
};

const nodeTypes = {
  category: CategoryNode,
};

const rawNodesTB = [
  { id: 'Arrays & Hashing', position: { x: 400, y: 50 } },
  { id: 'Two Pointers', position: { x: 300, y: 150 } },
  { id: 'Stack', position: { x: 500, y: 150 } },
  { id: 'Binary Search', position: { x: 150, y: 250 } },
  { id: 'Sliding Window', position: { x: 350, y: 250 } },
  { id: 'Linked List', position: { x: 550, y: 250 } },
  { id: 'Trees', position: { x: 350, y: 350 } },
  { id: 'Tries', position: { x: 200, y: 450 } },
  { id: 'Heap / Priority Queue', position: { x: 400, y: 450 } },
  { id: 'Backtracking', position: { x: 600, y: 450 } },
  { id: 'Intervals', position: { x: 200, y: 550 } },
  { id: 'Greedy', position: { x: 400, y: 550 } },
  { id: 'Graphs', position: { x: 600, y: 550 } },
  { id: 'Advanced Graphs', position: { x: 500, y: 650 } },
  { id: '1-D Dynamic Programming', position: { x: 700, y: 650 } },
  { id: '2-D Dynamic Programming', position: { x: 600, y: 750 } },
  { id: 'Bit Manipulation', position: { x: 800, y: 750 } },
  { id: 'Math & Geometry', position: { x: 700, y: 850 } },
];

const rawNodesLR = [
  { id: 'Arrays & Hashing', position: { x: 50, y: 400 } },
  { id: 'Two Pointers', position: { x: 350, y: 300 } },
  { id: 'Stack', position: { x: 350, y: 500 } },
  { id: 'Binary Search', position: { x: 650, y: 150 } },
  { id: 'Sliding Window', position: { x: 650, y: 300 } },
  { id: 'Linked List', position: { x: 650, y: 450 } },
  { id: 'Trees', position: { x: 950, y: 300 } },
  { id: 'Tries', position: { x: 1250, y: 100 } },
  { id: 'Heap / Priority Queue', position: { x: 1250, y: 250 } },
  { id: 'Backtracking', position: { x: 1250, y: 450 } },
  { id: 'Intervals', position: { x: 1550, y: 150 } },
  { id: 'Greedy', position: { x: 1550, y: 250 } },
  { id: 'Graphs', position: { x: 1550, y: 450 } },
  { id: 'Advanced Graphs', position: { x: 1850, y: 350 } },
  { id: '1-D Dynamic Programming', position: { x: 1550, y: 600 } },
  { id: '2-D Dynamic Programming', position: { x: 1850, y: 500 } },
  { id: 'Bit Manipulation', position: { x: 1850, y: 700 } },
  { id: 'Math & Geometry', position: { x: 2150, y: 600 } },
];

const initialEdges = [
  { id: 'e-arrays-two', source: 'Arrays & Hashing', target: 'Two Pointers' },
  { id: 'e-arrays-stack', source: 'Arrays & Hashing', target: 'Stack' },
  { id: 'e-two-binary', source: 'Two Pointers', target: 'Binary Search' },
  { id: 'e-two-sliding', source: 'Two Pointers', target: 'Sliding Window' },
  { id: 'e-two-linked', source: 'Two Pointers', target: 'Linked List' },
  { id: 'e-binary-trees', source: 'Binary Search', target: 'Trees' },
  { id: 'e-sliding-trees', source: 'Sliding Window', target: 'Trees' },
  { id: 'e-linked-trees', source: 'Linked List', target: 'Trees' },
  { id: 'e-trees-tries', source: 'Trees', target: 'Tries' },
  { id: 'e-trees-heap', source: 'Trees', target: 'Heap / Priority Queue' },
  { id: 'e-trees-backtracking', source: 'Trees', target: 'Backtracking' },
  { id: 'e-heap-intervals', source: 'Heap / Priority Queue', target: 'Intervals' },
  { id: 'e-heap-greedy', source: 'Heap / Priority Queue', target: 'Greedy' },
  { id: 'e-heap-advanced', source: 'Heap / Priority Queue', target: 'Advanced Graphs' },
  { id: 'e-backtracking-graphs', source: 'Backtracking', target: 'Graphs' },
  { id: 'e-backtracking-1d', source: 'Backtracking', target: '1-D Dynamic Programming' },
  { id: 'e-graphs-advanced', source: 'Graphs', target: 'Advanced Graphs' },
  { id: 'e-graphs-2d', source: 'Graphs', target: '2-D Dynamic Programming' },
  { id: 'e-1d-2d', source: '1-D Dynamic Programming', target: '2-D Dynamic Programming' },
  { id: 'e-1d-bit', source: '1-D Dynamic Programming', target: 'Bit Manipulation' },
  { id: 'e-2d-math', source: '2-D Dynamic Programming', target: 'Math & Geometry' },
  { id: 'e-bit-math', source: 'Bit Manipulation', target: 'Math & Geometry' },
];

function RoadmapCanvas({ data, layout, onCategoryClick }) {
  const { fitView } = useReactFlow();

  const rawNodes = layout === 'TB' ? rawNodesTB : rawNodesLR;

  const nodes = useMemo(() => {
    return rawNodes.map(node => {
      const cat = data?.categories?.find(c => c.name === node.id);
      let solved = 0;
      let total = 0;
      
      if (cat) {
        total = cat.problems.length;
        solved = cat.problems.filter(id => data.problems[id]?.is_solved).length;
      }
      
      return {
        ...node,
        type: 'category',
        data: {
          label: node.id,
          solved,
          total,
          layout,
          onCategoryClick
        }
      };
    });
  }, [data, layout]);

  // Optionally re-fit view when layout changes
  React.useEffect(() => {
    setTimeout(() => {
      fitView({ padding: 0.2, duration: 800 });
    }, 50);
  }, [layout, fitView]);

  return (
    <ReactFlow 
      nodes={nodes} 
      edges={initialEdges}
      nodeTypes={nodeTypes}
      fitView
      minZoom={0.2}
      maxZoom={1.5}
      defaultEdgeOptions={{ 
        type: 'smoothstep',
        style: { stroke: '#475569', strokeWidth: 2 },
        animated: false
      }}
      proOptions={{ hideAttribution: true }}
    >
      <Background color="#334155" gap={24} size={1} />
      <Controls style={{ background: '#1e293b', fill: '#e2e8f0' }} />
    </ReactFlow>
  );
}

export default function Roadmap({ data, onCategoryClick }) {
  const [layout, setLayout] = useState('TB');

  return (
    <div style={{ width: '100%', height: '100%', position: 'relative' }}>
      <div style={{ position: 'absolute', top: 20, right: 20, zIndex: 10, display: 'flex', gap: '0.5rem', background: 'rgba(0,0,0,0.5)', padding: '0.5rem', borderRadius: '8px' }}>
        <button 
          onClick={() => setLayout('TB')}
          style={{
            background: layout === 'TB' ? 'var(--accent-color)' : 'rgba(255,255,255,0.1)',
            border: 'none',
            color: '#fff',
            padding: '0.4rem 0.8rem',
            borderRadius: '4px',
            cursor: 'pointer',
            fontSize: '0.85rem'
          }}
        >
          Top to Bottom
        </button>
        <button 
          onClick={() => setLayout('LR')}
          style={{
            background: layout === 'LR' ? 'var(--accent-color)' : 'rgba(255,255,255,0.1)',
            border: 'none',
            color: '#fff',
            padding: '0.4rem 0.8rem',
            borderRadius: '4px',
            cursor: 'pointer',
            fontSize: '0.85rem'
          }}
        >
          Left to Right
        </button>
      </div>
      <ReactFlowProvider>
        <RoadmapCanvas data={data} layout={layout} onCategoryClick={onCategoryClick} />
      </ReactFlowProvider>
    </div>
  );
}
